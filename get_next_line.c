/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/19 08:09:50 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 3
// #include <stdio.h>

char	*ft_freedup(char **s)
{
	char	*ret;

	ret = ft_strdup(*s);
	free(*s);
	return (ret);
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*ret;
	ret = ft_strjoin(s1, s2);
	free(s1);
	return (ret);
}

char	*ft_strcut(char *s, char sep, char **save)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	while (s[i] != sep)
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s != sep)
		ret[i++] = *s++;
	ret[i++] = *s++;
	ret[i] = '\0';
	tmp = *save;
	if (*save)
		*save = ft_strdup(s);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*save = NULL;
	int			char_read;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	if (save && ft_charinstr(save, '\n'))
		return (ft_strcut(save, '\n', &save));
	ret = NULL;
	if (save)
		ret = ft_freedup(&save);
	char_read = BUFFER_SIZE;
	while (char_read == BUFFER_SIZE)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
			return (NULL);
		buffer[(int)char_read] = '\0';
		if (char_read && ft_charinstr(buffer, '\n'))
		{
			if (ret)
				return (ft_freejoin(ret, ft_strcut(buffer, '\n', &save)));
			else
				return (ft_strcut(buffer, '\n', &save));
		}
		else if (*buffer)
		{
			if (ret)
				ret = ft_freejoin(ret, ft_strcut(buffer, '\0', &save));
			else
				ret = ft_strcut(buffer, '\0', &save);
		}
	}
	if (ret)
		return (ret);
	return (NULL);
}
