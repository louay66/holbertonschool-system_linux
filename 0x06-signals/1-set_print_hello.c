#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "signals.h"
/**
 * print_hello - print a message when detacted the ctr-c
 * @n: is the signum
 * Return:  void
 */

void print_hello(int n __attribute__((unused)))
{
	write(STDOUT_FILENO, "Hello :)\n", 9);
}

/**
 * set_print_hello - detacted the ctr-c
 * Return:  void
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
