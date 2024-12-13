#include "get_next_line.h"

char	*ft_strjoin(char  *cpy, char *buff)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	total_len;
	char			*s_join;

    if(!cpy)
    {
        return (buff);
    }
	total_len = ft_strlen(cpy) + ft_strlen(buff);
	s_join = malloc(sizeof(char) * total_len +1);
	if (s_join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (cpy[i] != '\0')
	{
		s_join[i] = cpy[i];
		i++;
	}
	while (buff[j] != '\0')
	{
		s_join[i] = buff[j];
		i++;
		j++;
	}
	s_join[i] = '\0';
	return (s_join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}


int	ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while(s[i])
		i++;
	return (i);
}
