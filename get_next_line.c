/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/09/27 22:47:30 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	ret = malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && *s1)
		ret[i++] = *s1++;
	while (i < len && *s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
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

char	*ft_get_next_line(int fd)
{
	char		*buf;
	int			char_read;
	static char	*ret;

	int i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buf)
		return (NULL);
	
	while ((char_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[char_read] = '\0';
		printf("LOOP %d - char_read: %d - %s\n", i, char_read, buf);
		if (!ret && char_read)
			ret = ft_strjoin(ft_strnew(1), buf);
		else
		{
			free(ret);
			ret = ft_strjoin(ret, buf);
		}
		i++;
	}
	printf("%s\n", ret);
	return (ret);
}
