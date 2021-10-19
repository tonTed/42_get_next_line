#include "get_next_line.h"

#define BUFFER_SIZE 1

char	*ft_realloc(char *tofree, char *newchar)
{
	free(tofree);
	return (newchar);
}

void	*ft_freenull(char **ptr)
{
	free(*ptr);
	return (NULL);
}

char	*ft_strcut(char *s, char c, char **save)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i++] != c)
		len++;
	len++;
	ret = (char *)malloc(((len + 1) * sizeof(char)));
	if (!ret)
		return (NULL);
	i = 0;
	while (len--)
		ret[i++] = *s++;
	ret[i] = '\0';
	if (*save)
		free(*save);
	*save = ft_strdup(s);
	return (ret);
}

char	*ft_setting(char **save, int *char_read)
{
	char	*ret;

	*char_read = BUFFER_SIZE;
	if (!*save)
		ret = ft_strdup("");
	else if (ft_charinstr(*save, '\n'))
	{
		char_read = 0;
		ret = ft_strcut(*save, '\n', &*save);
	}
	else
	{
		ret = ft_strdup(*save);
		free(*save);
		*save = NULL;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			char_read;
	static char	*save;

	ret = ft_setting(&save, &char_read);
	while (ft_charinstr(ret, '\n') == 0 && char_read == BUFFER_SIZE)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1 )
			return (ft_freenull(&ret));
		buffer[char_read] = '\0';
		ret = ft_realloc(ret, ft_strjoin(ret, buffer));
		if (ft_charinstr(ret, '\n') != 0)
			ret = ft_realloc(ret, ft_strcut(ret, '\n', &save));
	}
	if (*ret == '\0')
		return (ft_freenull(&ret));
	return (ret);
}