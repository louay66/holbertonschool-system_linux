#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "signals.h"

/**
 * handler - msg handler
 *@num: number of signum of signal
 */
void handler(int num)
{
	printf("Caught %d\n", num);
}
/**
 * main - descreption of signum
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	struct sigaction action;

	action.sa_handler = handler;
	sigaction(SIGINT, &action, NULL);
	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
