/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/26 11:21:20 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*ft_free(char *ptr1, char *ptr2, char **sptr, char *ret)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	if (sptr)
	{
		free(*sptr);
		*sptr = NULL;
	}
	return (ret);
}

char	*ft_strcut(char **save, char sep, int *continue_)
{
	char	*tmp;
	char	*ret;
	size_t	len;
	int		i;

	len = ft_charinstr(*save, sep) + 1;
	if (save[len] == '\0')
		return (*save);
	ret = malloc(sizeof(char) * (len + 1));
	*continue_ = 0;
	if (!ret)
		return (NULL, NULL, *save, NULL);
	tmp = *save;
	i = 0;
	while (*(*save) != sep)
		ret[i++] = *(*save++);
	ret[i++] = *(*save++);
	ret[i] = '\0';
	*save = ft_strdup(*save);
	free(tmp);
	return (ret);
}

char	*ft_readline(int fd, char **save, char sep, char continue_)
{
	char	*buffer;
	int		char_read;
	char	*ret;

	char_read = BUFFER_SIZE;
	while (continue_ && char_read == BUFFER_SIZE)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (ft_free(buffer, NULL, save, NULL));
		char_read = read(fd, buffer, BUFFER_SIZE);
		buffer[char_read] = '\0';
		if (*save)
			ret = ft_strjoin()
		return (NULL);
	}
	return(buffer);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	int			continue_;
	char		sep;
	char		*ret;
	
	if (read(fd, save, 0) == -1 || BUFFER_SIZE <= 0)
		return (ft_free(NULL, NULL, &save, NULL));
	sep = '\n';
	if (save && *save)
		ret = ft_strcut(&save, sep, &continue_);
	if (continue_)
		ret = ft_readline(fd, &save, sep, continue_);



	if (continue_ != 0)
		return (ft_strcut(save, sep, &save));
	return (ft_readline(fd, &save, sep, continue_));
}
