#include "multithreading.h"

/**
 * tprintf-that uses the printf family to print out a given formatted string.
 *@format: holds the address of a string that must be printed
 * Return: EXIT_SUCCESS
 */
int tprintf(char const *format, ...)
{
	printf("[%lu] %s", pthread_self(), format);
	return (EXIT_SUCCESS);
}
