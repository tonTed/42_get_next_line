/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/01 16:48:06 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 42

char	*ft_strjoin(char *ret, char **buf, int len_buf)
{
	char	*new_ret;
	int		i;

	new_ret = (char *)malloc((ft_strlen(ret) + len_buf + 1) * sizeof(char));
	if (!new_ret)
		return (NULL);
	i = 0;
	while (*ret)
		new_ret[i++] = *ret++;
	while (**buf && **buf != '\n')
		new_ret[i++] = *(*buf)++;
	new_ret[i++] = *(*buf)++;
	new_ret[i] = '\0';
	return (new_ret);
}

char	*ft_prejoin(char *ret, char *buf, int *continue_, char **save)
{
	int		len;
	char	*tmp;
	// char	*new_ret;

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
	static char	*save = "";
	char		*ret;
	int			char_read;
	int			continue_;
	char		*tmp;

	continue_ = 1;
	char_read = 1;
	ret = ft_strdup("");
	tmp = ret;
	ret = ft_prejoin("", save, &continue_, &save);
	free(tmp);
	while (continue_ && char_read)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == - 1 || (char_read == 0 && ret[0] == '\0'))
		{
			free(ret);
			return (NULL);
		}
		printf("char_read: %d, buffer: %s\n",char_read, buf);
		buf[char_read] = '\0';
		tmp = ret;
		ret = ft_prejoin(ret, buf, &continue_, &save);
		free(tmp);
	}
	// printf("ret: %s - save: %s", ret, save);
	return (ret);
}
