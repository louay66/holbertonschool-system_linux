C= gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99 -g

SRC0 = 0-strace.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = strace_0
strace_0: syscalls.h $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)