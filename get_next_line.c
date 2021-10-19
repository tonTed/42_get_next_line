/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/19 10:57:35 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		char_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*ret;
	// char	*tmp;

	// if (fd < 0)
	// 	return (NULL);
	ret = NULL;
	// printf ("fd: %d\n", fd);
	char_read = BUFFER_SIZE;
	while (char_read == BUFFER_SIZE)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		// printf ("char_read: %d\n", char_read);
		if (char_read == -1)
			return (NULL);
		buffer[char_read] = '\0';
		if (ret)
			ret = ft_strjoin(ret, buffer);
		else
			ret = ft_strdup(buffer);
	}
	// if (!ret)
	// 	ret = ft_strdup(buffer);
	// else
	// {
	// 	tmp = ret;
	// 	ret = ft_strjoin(ret, buffer);
	// 	free(tmp);
	// } 
	
	return (ret);
}
