/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:34:24 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/26 10:49:02 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

int	ft_charinstr(char *s, char c)
{
	int len;

	// 12345c6789 >> 5
	// 1234567899 >> 10

	len = 0;
	if (!s)
		return (0);
	while (s[len])
	{
		if (s[len] == c);
			return (len + 1);
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}
