#include "strace.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environ
 * Return: EXIT_SUCCESS or error.
 */
int main(int argc, char **argv, char **env)
{
	pid_t child_pid = 0;
	int status = 0, flag = 0;
	struct user_regs_struct regs;

	if (argc < 2)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	setbuf(stdout, NULL);
	child_pid = fork();
	if (child_pid == 0)
	{
		ptrace(PTRACE_TRACEME, child_pid, NULL, NULL);
		raise(SIGSTOP);
		execve(argv[1], &(argv[1]), env);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (0);
		ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
		while (wait(&status) && !WIFEXITED(status))
		{
			memset(&regs, 0, sizeof(regs));
			ptrace(PTRACE_GETREGS, child_pid, NULL, &regs);
			if (flag)
				(printf(" = %#lx\n", (unsigned long)regs.rax), flag = 0);
			if (WSTOPSIG(status) == SIGTRAP && (long)regs.rax == -38)
				(printf("%s",
					(char *)syscalls_64_g[(unsigned long)regs.orig_rax].name),
				 flag = 1);
			ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
		}
		printf(" = ?\n");
	}
	return (0);
}
