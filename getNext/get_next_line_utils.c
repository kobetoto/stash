#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>

char *check_and_cut(char *s) 
{
    int i;
    char *rslt;
    char *nl;

    rslt = malloc(sizeof(char) * );//...........malloc!
    if (!rslt)
        return (NULL);

    nl = ft_strchr(s, '\n');
    if (nl == NULL) 
	{
        free(rslt);
        return (s);
    }
	i = 0;
    while (&s[i] != nl) 
	{
        rslt[i] = s[i];
        i++;
    }
	rslt[i] = '\n';
    rslt[i+1] = '\0';  

    return (rslt);
}

char *ft_strchr(const char *s, int c) 
{
    int i = 0;
    while (s[i]) 
	{
        if ((unsigned char)s[i] == (unsigned char)c)
            return ((char *)&s[i]);
        i++;
    }
    if ((unsigned char)c == '\0')
        return ((char *)&s[i]);
    return (NULL);
}
