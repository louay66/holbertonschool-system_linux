CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC0 = request.c socketBoot.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = todo_api_0

SRC1 = Queries.c socketBoot.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = todo_api_1

SRC2 = Headers.c socketBoot.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = todo_api_2

SRC3 = Body.c socketBoot.c
OBJ3 = $(SRC3:.c=.o)
NAME3 = todo_api_3

todo_api_0: http.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

todo_api_1: http.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)


todo_api_2: http.h $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)


todo_api_3: http.h $(OBJ3)
	$(CC) $(OBJ3) -o $(NAME3)