#include "get_next_line.h"


char *get_next_line(int fd)
{
	char			*line;
	char			*buff;
	static char		*cpy;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,&line,0) < 0)
		return (NULL);
	
	//read() & buff
	buff = ft_read(fd);

	//cpy en cours
	//probleme sur ma cpy avec allocation memoire
	cpy = ft_strjoin(cpy, buff);
	free(buff);

	return (cpy);
}

/*------read------*/
char	*ft_read(int fd)
{
	char			*buffer;
	int				char_read;

	//1. malloc buffer
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(buffer == NULL)
			return (NULL);
	//2. call read()
	char_read = read(fd,buffer,BUFFER_SIZE);
	if(char_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
