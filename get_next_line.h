/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:04:05 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/25 19:09:52 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/* utils libft */
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_charinstr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

/* get_next_line */
char	*ft_setting(char **save, int *char_read, char **buffer);

#endif