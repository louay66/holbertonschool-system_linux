#include "strace.h"

void trace_child(char **argv, char **env);
void trace_parent(pid_t child_pid);
int await_syscall(pid_t child_pid);

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environ
 * Return: EXIT_SUCCESS or error.
 */
int main(int argc, char **argv, char **env)
{
	pid_t child_pid;

	if (argc < 2)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	setbuf(stdout, NULL);
	child_pid = fork();
	if (child_pid == -1)
	{
		dprintf(STDERR_FILENO, "Fork failed: %d\n", errno);
		exit(-1);
	}
	else if (!child_pid)
	{
		trace_child(argv, env);
	}
	else
	{
		trace_parent(child_pid);
	}
	return (0);
}

/**
 * trace_child - traces child process
 * @argv: argument vector for execute
 * @env: environ
 * Return: void.
 */
void trace_child(char **argv, char **env)
{
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	kill(getpid(), SIGSTOP);
	if (execve(argv[1], argv + 1, env) == -1)
	{
		dprintf(STDERR_FILENO, "Exec failed: %d\n", errno);
		exit(-1);
	}
}

/**
 * trace_parent - traces parent process
 * @child_pid: the id of process
 * Return: void.
 */
void trace_parent(pid_t child_pid)
{
	int status;
	struct user_regs_struct regs;

	waitpid(child_pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (await_syscall(child_pid))
			break;
		memset(&regs, 0, sizeof(regs));
		ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
		printf("%lu\n", (long)regs.orig_rax);
		if (await_syscall(child_pid))
			break;
	}
}

/**
 * await_syscall - waits for a syscall
 * @child_pid: pid of process to await
 * Return: 0 if child stopped, 1 if exited
 */
int await_syscall(pid_t child_pid)
{
	int status;

	while (1)
	{
		ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
		waitpid(child_pid, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (0);
		if (WIFEXITED(status))
			return (1);
	}
}
