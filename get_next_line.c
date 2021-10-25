/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:54 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/25 19:24:05 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcut(char *s,char c)
{
	
}

char	*ft_readline(int fd, char *save)
{
	
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	
	if (fd < 0)
		return (NULL);
	if (save && ft_charinstr(save, '\n'))
		return (ft_strcut(save, '\n'));
	return (ft_readline(fd, save));
}
