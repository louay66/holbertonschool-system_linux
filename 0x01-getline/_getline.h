#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define READ_SIZE 1024

/**
 * struct list_s - linked list for file descriptor.
 * @fd: The file descriptor .
 * @buffer: The buffer associated to fd.
 * @data: data
 * @next: The pointer to the next node
 */
typedef struct list_s
{
   int fd;
   char *buffer;
   int data;
   struct list_s *next;
} list_t;

char *_getline(const int fd);
char *_parser(list_t *scan);

#endif /* __GETLINE_H_ */