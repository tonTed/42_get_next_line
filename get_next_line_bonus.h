/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:33:14 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/28 09:25:56 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define SEP '\n'

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// returns the next new line in tje file descriptors, null at the end.
char	*get_next_line(int fd);

// returns the index of the first separator, if not exists returns -1.
int		ft_charinstr(char *s, char sep);

// returns the len of the string.
size_t	ft_strlen(char *s);

// returns a string with the two strings concatenate, can be free().
// the first string must be free().
char	*ft_freejoin(char *s1, char *s2);

// The ft_strdup() function allocates sufficient memory for a copy of the 
// string s, does the copy, and returns a pointer to it. The pointer may
// subsequently be used as an argument to the function free(3).
char	*ft_strndup(char *s, size_t len);

#endif