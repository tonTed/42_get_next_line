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
char	*get_next_line(int fd);

# include <stdio.h>
#endif