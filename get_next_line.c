/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/04 11:01:23 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#define BUFFER_SIZE 8

int		ft_charinstr(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_strcut(char *s, char c)
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
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			char_read;
	char		*tmp;

	ret = ft_strdup("");
	while (ft_charinstr(ret, '\n') == 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		buffer[char_read] = '\0';
		tmp = ret;
		ret = ft_strjoin(ret, buffer);
		free(tmp);
		if (ft_charinstr(ret, '\n') != 0)
		{
			tmp = ret;
			ret = ft_strcut(ret, '\n');
			free(tmp);
		}
	}
	if (*ret == '\0')
		return (NULL);

	return (ret);
}
