#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "signals.h"
/**
 * current_handler_sigaction - recive the signel
 *
 * Return:returns a pointer to the current handler
 * of SIGINT, or NULL on failure
 */

void (*current_handler_sigaction(void))(int)
{
	struct sigaction action;

	if (sigaction(SIGINT, NULL, &action) == -1)
		return (NULL);
	else
		return (action.sa_handler);
}
