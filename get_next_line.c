/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/09/30 22:25:50 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 1

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *ret, char **buf, int len_buf)
{
	char	*ret_;
	int		i;

	ret_ = (char *)malloc((ft_strlen(ret) + len_buf + 1) * sizeof(char));
	if (!ret_)
		return (NULL);
	i = 0;
	while (*ret)
		ret_[i++] = *ret++;
	while (**buf && **buf != '\n')
		ret_[i++] = *(*buf)++;
	ret_[i++] = *(*buf)++;
	ret_[i] = '\0';
	return (ret_);
}

char	*ft_prejoin(char *ret, char *buf, int *continue_, char **save)
{
	int		len;
	char	*tmp;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	ret = ft_strjoin(ret, &buf, len + 1);
	if (*(buf - 1) == '\n')
	{
		*continue_ = 0;	
		if (*buf)
		{
			tmp = *save;
			*save = ft_strdup(buf);
			free(tmp);
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			char_read;
	static char	*save = "";
	char		*ret;
	int			continue_;
	char		*tmp;

	continue_ = 1;
	char_read = 1;
	ret = ft_prejoin("", save, &continue_, &save);
	save = ft_strdup(save);
	while (continue_ && char_read)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == - 1 || (char_read == 0 && ret[0] == '\0'))
		{
			free(ret);
			free(save);
			return (NULL);
		}
		buf[char_read] = '\0';
		tmp = ret;
		ret = ft_prejoin(ret, buf, &continue_, &save);
		free(tmp);
	}
	// printf("%s\n", ret);
	return (ret);
}
