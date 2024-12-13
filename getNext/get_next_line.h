#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 1
#endif


char    *get_next_line(int fd);
char	*ft_read(int fd);
char	*ft_strjoin(char  *cpy, char *buff);
char	*ft_strchr(const char *s, int c);
int	        ft_strlen(char *s);
