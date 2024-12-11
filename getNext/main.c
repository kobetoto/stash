#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"


int main()
{
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		return 1;
	}
	while (1)
	{
	line = get_next_line(fd);
	printf("==%s==",line);
	if (!line)
	{
		break;
	}
	free (line);
	}
}
