/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:15:52 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/10 12:53:01 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{

	/*				variable & init				*/
	char		*tmp;
	char		*line;
	int		i;


	i = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);


	if (fd < 0)
	{
		free(tmp);
		return (NULL);
	}

	tmp = read_and_add(fd, BUFFER_SIZE);
	if (!tmp)
	{
		free (tmp);
		return (NULL);
	}

	printf("    tmp:\n        ==%s==\n\n",tmp);
	//function pour copier jusquau /n
	line = cp_line(tmp);-----------------------------------
	
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;	
	}
	line [i] = '\n';
	printf("    line:\n        ==%s==\n\n",line);
	free(tmp);
	return (line);
}


char	*read_and_add(int fd, int buffer)
{
	/*				variable & init				*/
	char            *buff;
	static char     *tmp;
	int             i;
	int             char_;

	buff = NULL;
	char_ = 0;
	i = 0;
	tmp = malloc(sizeof(char) * (buffer +1));
	buff = malloc(sizeof(char) * (buffer));
	if (!tmp || !buff)
		return (NULL);


	/*				READ & stock				*/
	char_ = (int)read(fd, buff,buffer);
	if(char_ <= 0)
	{
		free(buff);
		perror("errrrror");
		return (NULL); 
	}
	printf("    buff:\n        ==%s==\n\n",buff);

	while (buff[i] && i < char_)
	{
		tmp[i] = buff[i];
		i ++;
	}
	tmp[i] = '\0';
	free(buff);
	return (tmp);
}

char	*cp_line(char *s)
{
to do.....
}
i
