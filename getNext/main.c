#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
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
	if (!line)
	{
		break;
	}
	printf("    gnl:\n        ===%s===\n\n\n",line);
	free (line);
	}
}
