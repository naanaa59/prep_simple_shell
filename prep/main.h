#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char **get_command(void);
int file_exists_in_path(const char *filename);
char *_getenv(const char *name);
struct Node
{
	char data[255];
	struct Node *next;
};

typedef struct Node Node;
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
#endif
