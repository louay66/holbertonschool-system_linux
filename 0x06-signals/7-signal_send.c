#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "signals.h"
/**
 * main - descreption of signum
 *@argc: number of arguments
 *@argv: command line arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1] == 0)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		if (kill(atoi(argv[1]), 2) == -1)
		{
			printf("Usage: %s <pid>\n", argv[0]);
			return (EXIT_FAILURE);
		}
		else
		{
			return (EXIT_SUCCESS);
		}
	}
}
