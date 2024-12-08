#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*line;

	if (fd <= 0)
		return (NULL);
	/*READ FD & add it to tmp*/
	line = read_and_add(fd, BUFFER_SIZE);
	return (line);
}


char	*read_and_add(int fd, int buffer)
{
	char            *line;
	char static     *tmp;
	int             i;
	int             char_;

	tmp = malloc(sizeof(char) * (buffer));
	if (!tmp)
		return (NULL);
	char_ = (int)read(fd, tmp,buffer);
	if(char_ <= 0)
	{
		free(tmp);
		//perror("errrrror");
		return (NULL); 
	}
	printf("    tmp:\n        ==%s==\n\n\n\n",tmp);
	line = malloc(sizeof(char) * (buffer + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0' && i < char_)
	{
	
		line[i] = tmp[i];
		if (tmp[i] == '\n')
		{
		}
		i ++;
	}
	line[i] = '\n';
	line[i+1] = '\0';
	free(tmp);
	return (line);
}
