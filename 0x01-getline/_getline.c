#include "_getline.h"

/**
 * _getline - reads an entire line from file descriptor.
 * @fd:	file descriptor
 * Return: splited string without null "/0" end of line.
 **/
char *_getline(const int fd)
{
	static list_t *getline;
	list_t *scan;
	char *info;
	int data;

	/* loop through all the data we have via linked list struct*/
	for (scan = getline; scan; scan = scan->next)
		if (scan->fd == fd)
		{
			if (scan->data <= 0)
				scan->data = read(fd, scan->buffer, READ_SIZE);
			return (_parser(scan));
		}
	info = malloc(sizeof(char) * READ_SIZE);
	data = read(fd, info, READ_SIZE);
	if (data <= 0)
	{
		free(info);
		return (NULL);
	}
	scan = malloc(sizeof(list_t));
	if (scan == NULL)
		return (NULL);
	scan->fd = fd;
	scan->buffer = info;
	scan->data = data;
	scan->next = getline;
	getline = scan;
	return (_parser(scan));
}
/**
 * _parser - parse split and handle strings and lines.
 * @scan: pointer to scanned data.
 * Return: pointer to line.
 **/
char *_parser(list_t *scan)
{
	int i, j;
	int line_size = 0;
	int copy_data = 0;
	char *line = NULL, *tmp;

	while (scan->data > 0)
	{
		if (line_size < copy_data + scan->data + 1)
		{
			line_size += scan->data + 1, tmp = malloc(sizeof(char) * line_size);
			if (tmp == NULL)
			{
				free(line);
				return (NULL);
			}
			memcpy(tmp, line, copy_data);
			memset(tmp + copy_data, '\0', line_size - copy_data);
			free(line);
			line = tmp;
		}
		for (i = 0; i < scan->data; i++)
			if (scan->buffer[i] == '\n')
			{
				scan->buffer[i++] = '\0', scan->data -= i;
				memcpy(line + copy_data, scan->buffer, i);
				for (j = 0; i < READ_SIZE; j++, i++)
					scan->buffer[j] = scan->buffer[i];
				for (; j < READ_SIZE; j++)
					scan->buffer[j] = '\0';
				return (line);
			}
		memcpy(line + copy_data, scan->buffer, scan->data);
		copy_data += scan->data;
		scan->data = read(scan->fd, scan->buffer, READ_SIZE);
	}

	return (line);
}
