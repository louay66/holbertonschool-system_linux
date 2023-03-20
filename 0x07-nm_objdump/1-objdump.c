#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 * @argc: The number of arguments passed
 * @argv: An array of strings containing the arguments
 * @env: An array of strings containing the environment variables
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE if an error occurs
 */

int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/objdump", "-s", "-f", "", NULL};

	(void)argc;
	args[3] = argv[1];
	if (execve("/usr/bin/objdump", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
