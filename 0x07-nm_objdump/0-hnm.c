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
	char *comm[] = {"./hnm", "-p", "", NULL};

	comm[2] = argv[1];

	if (execve("/usr/bin/nm", comm, env) == -1)
	{
		perror("execve");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
