#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "color.h"
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 1024
#define ARG_SIZE 64
#define LIMITERS " \t\r\n\a"

char *read_line(void);
char **parse_line(char *line);
void printer(char **pptr);
void list();
