/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:04:05 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/26 10:45:31 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 82
# endif

/* utils libft */
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int     ft_charinstr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

/* get_next_line */
char	*get_next_line(int fd);

#endif