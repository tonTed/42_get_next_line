/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:12 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/28 02:53:47 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_color.h"

int		ft_getindex(int fd, char **save)
{
	int		char_read;
	char	*buffer;

	char_read = BUFFER_SIZE;
	while ((ft_charinstr(*save, SEP) == -1) && (char_read == BUFFER_SIZE))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return(0);
		char_read = read(fd, buffer, BUFFER_SIZE);
		buffer[char_read] = '\0';
		*save = ft_freejoin(*save, buffer);
		free(buffer);
		if (!*(*save))
		{
			free(*save);
			*save = NULL;
			return (0);
		}
	}
	return (ft_charinstr(*save, SEP));
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*ret;
	int			index;
	char		*tmp;

	if (read(fd, save, 0) < 0)
		return (NULL);
	index = ft_getindex(fd, &save);
	if (!save)
		return (NULL);
	if (index == -1 || save[index + 1] == '\0')
	{
		ret = ft_freejoin(NULL, save);
		free(save);
		save = NULL;
	}
	else
	{
		ret = ft_strndup(save, index + 1);
		tmp = save;
		save = ft_freejoin(NULL, &save[index + 1]);
		free(tmp);
		tmp = NULL;
	}
	return (ret);
}