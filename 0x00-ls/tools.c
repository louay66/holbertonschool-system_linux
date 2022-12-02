#include <unistd.h>
#include "main.h"

/**
 * *_strcpy -pointer
 * @dest: pointer
 * @src:pointer
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a]; a++)
	{
		dest[a] = src[a];
	}
	dest[a++] = '\0';
	return (dest);
}
/**
 **_strcat - past the second input in the first input
 *@dest:first input
 *@src:second input
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

char *_strcat(char *dest, char *src)
{
	int i, c;

	for (c = 0; dest[c] != '\0'; c++)
	{
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[c + i] += src[i];
	}
	dest[c + i] = '\0';
	return (dest);
}
