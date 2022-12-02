#include "main.h"
/**
 * main - function that take name of diractory and display all file inside it
 * @argc: anmber of arguments
 *@argv: arguments
 * Return: int
 */

int main(int argc, __attribute__((unused)) char *argv[])
{
	DIR *dir;
	char buffer[80];
	int status;
	int i, j;

	if (argc < 2)
	{
		return (ls_dir("./", 0));
	}
	else if (argc < 3)
	{
		strcpy(buffer, argv[1]);
		return (ls_dir(buffer, 0));
	}
	else
	{
		char multybuff[80];

		for (i = 1; i < argc; i++)
		{
			dir = opendir(argv[i]);
			if (!dir)
			{
				printf("./hls: cannot access '%s': No such file or directory\n", argv[i]);
				continue;
			}
		}
		for (j = 1; j < argc; j++)
		{
			dir = opendir(argv[j]);
			if (!dir)
			{
				continue;
			}
			strcpy(multybuff, argv[j]);
			status += ls_dir(multybuff, 1);
		}

		return (status);
	}
	return (-1);
}

/**
 * ls_dir - function that take name of diractory and display all file inside it
 * @buff: name of dir
 *@bool: check if has multy diractory or not
 * Return: int
 */
int ls_dir(char *buff, int bool)
{
	DIR *dir;
	struct dirent *read;
	char buffer[80];

	strcpy(buffer, buff);

	dir = opendir(buffer);

	if (!dir)
	{
		printf("./hls: cannot access '%s': No such file or directory\n", buffer);
		return (-1);
	}
	if (bool == 1)
	{
		printf("%s:\n", buffer);
	}
	while ((read = readdir(dir)) != NULL)
	{
		char pathname[] = "./";

		strcat(pathname, buffer);
		strcat(pathname, "/");
		strcat(pathname, read->d_name);

		if (read->d_name[0] == '.')
			continue;

		else
		{

			printf("%s  ", read->d_name);
		}
	}
	printf("\n");
	closedir(dir);
	return (0);
}
