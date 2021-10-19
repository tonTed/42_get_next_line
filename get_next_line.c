/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/19 13:31:55 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1
#include <stdio.h>

char	*ft_strcut(char **s, char sep)
{
	int		i;
	char	*ret;
	
	i = 0;
	while ((*s)[i] != sep)
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while ((*s)[i] != sep)
	{
		ret[i] = (*s)[i];
		i++;
	}
	ret[i] = (*s)[i];
	ret[i + 1] = '\0';
	(*s)[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	int			char_read;
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	static char	*save = NULL;
	char		*tmp;

	// if (fd < 0)
	// 	return (NULL);
	ret = NULL;
	// printf ("fd: %d\n", fd);
	char_read = BUFFER_SIZE;
	while (char_read == BUFFER_SIZE)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);

		/* check error read/file */
		if (char_read == -1)
			return (NULL);
	
		/* check end buffer and ret empty */
		if (char_read == 0 && !ret)
			return (NULL);
		
		buffer[char_read] = '\0';
		/* check if ret is empty*/
		if (ret)
		{	
			tmp = ret;
			ret = ft_strjoin(ret, buffer);
			free(tmp);
		}
		else
			ret = ft_strdup(buffer);

		/* check '\n'*/
		if (ft_charinstr(ret, '\n'))
		{
			save = ft_strcut(&ret, '\n');
			return (ret);
		}
	}
	return (ret);
}
