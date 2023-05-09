#include "multithreading.h"

/**
 * thread_entry -  that will serve as the entry point to a new thread
 *@arg: holds the address of a string that must be printed
 * Return: EXIT_SUCCESS
 */
void *thread_entry(void *arg)
{
	char *str = (char *)arg;

	printf("%s\n", str);
	pthread_exit(NULL);
}
