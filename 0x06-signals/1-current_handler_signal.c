#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "signals.h"
/**
 * current_handler_signal - recive the signel
 *
 * Return:returns a pointer to the current handler
 * of SIGINT, or NULL on failure
 */

void (*current_handler_signal(void))(int)
{
	void (*handler)(int) = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);
	else
		return (handler);
}
