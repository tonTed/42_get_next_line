/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/04 09:44:27 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			char_read;

	char_read = read(fd, buffer, BUFFER_SIZE);
	buffer[char_read] = '\0';
	ret = ft_strdup(buffer);
	if (*ret == '\0')
		return (NULL);
	return (ret);
}
