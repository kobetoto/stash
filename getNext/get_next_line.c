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
	char		*line;// valeure a return
	char		*tmp;// valeure de stockage

		/*--check param--*/ 
	if (fd < 0)			 //chek FD
		return (NULL);

		/*--read & add --*/
	tmp = read_and_add(fd);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	/*--check & cut--*/
	line = check_and_cut(tmp);	
	return (line);
}


char	*read_and_add(int fd)
{
	static char			*tmp;    //gardera sa valeur a chaque appel de function
	char 				*buff;  // stock les value lu par read
	int					char_;//nombre de char lu par read()
	int					i;

	buff = NULL;
		/*--check param--*/ 
	if (fd < 0)			 //chek FD
		return (NULL);

		/*--malloc BUFF + TMP--*/
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff || !tmp)
			return (NULL);
			
		/*--read()--*/
		char_ = (int)read(fd, buff, BUFFER_SIZE);
		if (char_ <= 0)
			{
				free(buff);
				free(tmp);
				return (NULL);
			}
		i = 0;
		while (buff[i] && i < char_)
			{
				tmp[i] = buff[i];
				i++;
			}
		tmp[i] = '\0';
		return (tmp);
}
