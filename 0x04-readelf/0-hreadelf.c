#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - read ELF file with exeve
 * @argc: number of args
 * @argv: args  passed to program
 * @env:  the environment
 * Return: -1 in fail and 0 in success
 */
int main(int argc, char **argv, char *env[])
{
	char *readELF = "/usr/bin/readelf";
	char *args[4];

	if (argc != 2)
		exit(0);

	args[0] = readELF;
	args[1] = "-W";
	args[2] = "-h";
	args[3] = argv[1];
	args[4] = NULL;
	if (execve(readELF, args, env) == -1)
	{
		perror("Error: ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
