/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/09/29 23:36:08 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}

char	*ft_strjoin(char *ret, char  **buf, int len_buf)
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

char	*ft_strjoin_(char *ret, char *buf, int *continue_, char **save)
{
	int		len;
	char	*tmp_save;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] == '\n')
	{
		*save = (char *)malloc(sizeof(char) * (BUFFER_SIZE - len));
		if (!save)
			return (NULL);
		ret = ft_strjoin(ret, &buf, len + 1);
		*continue_ = 0;
		printf(" >> %s\n", buf);
	}
	return (ret);
}

// [0][1][2][3][4][5][6][7][8][9]
//  T  E  D  D  Y  /n B  L  A  N

//  10 - 5 = 5

char	*ft_get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			char_read;
	static char	*save;
	char		*ret;
	int			continue_;

	continue_ = 1;
	ret = "";
	while (continue_)
	{
		puts("########");
		char_read = read(fd, buf, BUFFER_SIZE);
		buf[char_read] = '\0';
		ret = ft_strjoin_(ret, buf, &continue_, &save);
	}
	printf("%s\n", ret);
	return (ret);
}
