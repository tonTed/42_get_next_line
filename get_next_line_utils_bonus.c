/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:36:00 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/28 09:28:05 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_charinstr(char *s, char sep)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == sep)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

char	*ft_strndup(char *s, size_t len)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s && *s && len--)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_freejoin(char *s1, char *s2)
{
	size_t	len;
	char	*ret;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*ret++ = s1[i++];
		free (s1);
	}
	if (s2)
		while (*s2)
			*ret++ = *s2++;
	*ret = '\0';
	return (ret - len);
}
