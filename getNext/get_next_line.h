#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 24
#endif


char *get_next_line(int fd);
char    *read_and_add(int fd, int buffer_size);
