/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:12 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/28 09:27:47 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_getindex(int fd, char **save)
{
	int		char_read;
	char	*buffer;

	char_read = BUFFER_SIZE;
	while ((ft_charinstr(*save, SEP) == -1) && (char_read == BUFFER_SIZE))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
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
	static char	*save[OPEN_MAX] = {NULL};
	char		*ret;
	int			index;
	char		*tmp;

	if (fd < 0 || read(fd, save, 0) < 0)
		return (NULL);
	index = ft_getindex(fd, &save[fd]);
	if (!save[fd])
		return (NULL);
	if (index == -1 || save[fd][index + 1] == '\0')
	{
		ret = ft_freejoin(NULL, save[fd]);
		free(save[fd]);
		save[fd] = NULL;
	}
	else
	{
		ret = ft_strndup(save[fd], index + 1);
		tmp = save[fd];
		save[fd] = ft_freejoin(NULL, &save[fd][index + 1]);
		free(tmp);
		tmp = NULL;
	}
	return (ret);
}
