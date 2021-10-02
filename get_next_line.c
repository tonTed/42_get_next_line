/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/02 18:47:35 by tblanco          ###   ########.fr       */
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
	while (buf[len] != '\0' && buf[len] != '\n')
		len++;
	ret = ft_strjoin(ret, &buf, len + 1);
	if (*buf == '\0' || *(buf - 1) == '\n')
	{
		*continue_ = 0;	
		if (*buf)
		{
			tmp = *save;
			// printf("BEFORE strdup > save: %s - buf: %s\n", *save, buf);
			*save = ft_strdup(buf);
			// printf("AFTER strdup > save: %s\n", *save);
			// free(tmp);
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
	ret = ft_prejoin("", save, &continue_, &save);
	while (continue_ && char_read)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		buf[char_read] = '\0';
		if (char_read == - 1 || (char_read == 0 && ret[0] == '\0'))
		{
			free(ret);
			return (NULL);
		}
		if (char_read)
		{
			tmp = ret;
			ret = ft_prejoin(ret, buf, &continue_, &save);
			free(tmp);
		}
		else
		{
			save = "";
			return (ret);
		}
	}
	return (ret);
}
