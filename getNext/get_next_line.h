#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 24
#endif


char *get_next_line(int fd);
char	*read_and_add(int fd);
char *check_and_cut(char *s);
char *ft_strchr(const char *s, int c);
