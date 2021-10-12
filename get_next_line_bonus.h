/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:04:05 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/12 19:32:35 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/* utils libft */
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_charinstr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

/* get_next_line */
char	*get_next_line(int fd);
char	*ft_realloc(char *tofree, char *newchar);
void	*ft_freenull(char **ptr);
char	*ft_strcut(char *s, char c, char **save);

#endif