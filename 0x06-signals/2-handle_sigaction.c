#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "signals.h"

/**
 * handler - msg handler
 *@num: number of signum of signal
 */
void handler(int num)
{
	printf("Gotcha! [%d]\n", num);
	fflush(stdout);
}

/**
 * handle_sigaction - catch the interprtur ctr-c
 * Return: 0 if success or -1 if failure
 */
int handle_sigaction(void)
{
	struct sigaction action;

	action.sa_handler = handler;

	return (sigaction(SIGINT, &action, NULL));
}
