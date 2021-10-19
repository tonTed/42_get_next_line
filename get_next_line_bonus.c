/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/19 18:50:14 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_realloc(char *tofree, char *newchar)
{
	if (tofree)
		free(tofree);
	return (newchar);
}

void	*ft_freenull(char **ptr, char **ptr2)
{
	if (*ptr)
		free(*ptr);
	if (*ptr2)
		free(*ptr2);
	return (NULL);
}

char	*ft_strcut(char *s, char sep, char **save)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i++] != sep)
		len++;
	len++;
	ret = (char *)malloc(((len + 1) * sizeof(char)));
	if (!ret)
		return (NULL);
	i = 0;
	while (len--)
		ret[i++] = *s++;
	ret[i] = '\0';
	if (*save)
		free(*save);
	*save = ft_strdup(s);
	return (ret);
}

char	*ft_setting(char **save, int *char_read, char **buffer)
{
	char	*ret;

	*char_read = BUFFER_SIZE;
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		return (NULL);
	if (!*save)
		ret = ft_strdup("");
	else if (ft_charinstr(*save, '\n'))
		ret = ft_strcut(*save, '\n', save);
	else
	{
		ret = ft_strdup(*save);
		free(*save);
		*save = NULL;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*ret;
	int			char_read;
	static char	*save[OPEN_MAX] = {NULL};

	if (fd < 0)
		return (NULL);
	ret = ft_setting(&save[fd], &char_read, &buffer);
	while (ret && ft_charinstr(ret, '\n') == 0 && char_read == BUFFER_SIZE)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1 )
			return (ft_freenull(&ret, &buffer));
		buffer[char_read] = '\0';
		ret = ft_realloc(ret, ft_strjoin(ret, buffer));
		if (ft_charinstr(ret, '\n') != 0)
			ret = ft_realloc(ret, ft_strcut(ret, '\n', &save[fd]));
	}
	if (!ret || *ret == '\0')
		return (ft_freenull(&ret, &buffer));
	if (buffer)
		free(buffer);
	return (ret);
}
