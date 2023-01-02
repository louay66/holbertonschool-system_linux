# \_getline.c

\_getline.c is a function that reads an entire line from a file descriptor.

## Usage

To use \_getline.c in your project, include the following line at the top of your C file:

```
   #include "_getline.h"
```

To read a line from a file descriptor, use the following code:

```
   char *line = _getline(fd);
```

Where fd is the file descriptor to read from. The function will return a pointer to the read line, without the null character ('\0') at the end of the line. If an error occurs or the end of the file is reached, the function will return NULL.

## Implementation Details

\_getline.c uses a linked list to store data read from the file descriptor. When the function is called, it first checks if there is already a node in the linked list with the same file descriptor. If there is, it returns the next line of data from that node. If there is no node with the same file descriptor, a new node is created and data is read into it from the file descriptor.

The function then calls the \_parser function to split the data into lines and return a pointer to the next line. If the end of the file is reached and there is no more data to be read, the function returns NULL.

## Caveats

\_getline.c reads data from the file descriptor in blocks of a fixed size (defined by the READ_SIZE macro). If a line is longer than this size, the function will need to be called multiple times to read the entire line.

Additionally, \_getline.c does not handle errors when reading from the file descriptor. If an error occurs, the function will return NULL without reporting the error. It is the responsibility of the caller to handle any errors that may occur when reading from the file descriptor.
