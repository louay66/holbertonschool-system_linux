#ifndef MAIN_H
#define MAIN_H

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int ls_dir(char *buff, int bool);

#endif
