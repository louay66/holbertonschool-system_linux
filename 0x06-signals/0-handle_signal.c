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
}

/**
 * handle_signal - catch the interprtur ctr-c
 * Return: 0 if success or -1 if failure
 */
int handle_signal(void)
{
	sig_t result;

	result = signal(SIGINT, handler);

	if (result == SIG_ERR)
		return (-1);
	else
		return (0);
}
