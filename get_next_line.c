/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/04 16:58:27 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

// #define BUFFER_SIZE 42

char	*ft_strcut(char *s, char c, char **save)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i++] != c)
		len++;
	len++;
	ret = (char *)malloc(((len + 1) * sizeof(char)));
	if (!ret)
		return (NULL);
	i = 0;
	while (len--)
		ret[i++] = *s++;
	ret[i] = '\0';
	
	/* save */
	if (*save)
		free(*save);
	*save = ft_strdup(s);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			char_read;
	char		*tmp;
	static char	*save;

	if (save)
	{
		ret = ft_strdup(save);
		free(save);
		// save = NULL;
	}
	else
		ret = ft_strdup("");
	save = NULL;

	if (ft_charinstr(ret, '\n'))
	{
		tmp = ret;
		ret = ft_strcut(ret, '\n', &save);
		free(tmp);
		return (ret);
	}

	char_read = BUFFER_SIZE;

	while (ft_charinstr(ret, '\n') == 0 && char_read == BUFFER_SIZE)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1 )
		{
			free(ret);
			// free(save);
			return (NULL);
		}
		buffer[char_read] = '\0';
		tmp = ret;
		ret = ft_strjoin(ret, buffer);
		free(tmp);
		if (ft_charinstr(ret, '\n') != 0)
		{
			tmp = ret;
			ret = ft_strcut(ret, '\n', &save);
			free(tmp);
		}
	}
	if (*ret == '\0')
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
