/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:08:55 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/19 13:43:41 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define LEN_TAB 50

/*
	fd < 0 : error
	fd = 0 : stdin 
	fd = 1 : stdout 
	fd = 2 : stderr
	fd > 2 : files open 
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

int main(void)
{
	int     fd[LEN_TAB];
	char    *s;
	int 	errors = 0;
	int		i;
	char	*ret;

	i = 0;

	/* 0 */
	fd[i] = -1;
	if ((s = get_next_line(fd[i])) != NULL)
/* 0 */	{printf("-- [%d]: fd(%d) negative must be return NULL >> %s\n",			i, fd[i], s);	errors++;}	i++;
	fd[i] = 5000;
	if ((s = get_next_line(fd[i])) != NULL)
/* 1 */	{printf("-- [%d]: fd(%d) doesn't exist must be return NULL >> %s\n",	i, fd[i], s);	errors++;}	i++;
	fd[i] = open("file", O_RDONLY); close(fd[i]);
	if ((s = get_next_line(fd[i])) != NULL)
/* 2 */	{printf("-- [%d]: fd(%d) close() must be return NULL >> %s\n", 			i, fd[i], s);	errors++;}	i++;
	fd[i] = open("empty", O_RDONLY);
	if ((s = get_next_line(fd[i])) != NULL)
/* 3 */	{printf("-- [%d]: fd(%d) file empty must be return NULL >> %s\n",		i, fd[i], s);	errors++;}	i++;
	fd[i] = open("10_no_nl", O_RDONLY);
	ret = "0123456789";
	s = get_next_line(fd[i]);
	if (s == NULL || strcmp(ret, s) != 0)
/* 4 */	{printf("-- [%d]: fd(%d) must be return %s >> %s\n",					i, fd[i], ret, s);	errors++;}	i++; free(s);

	fd[i] = open("10_nl", O_RDONLY);
	ret = "0123456789\n";
	s = get_next_line(fd[i]);
	if (s == NULL || strcmp(ret, s) != 0)
/* 5 */	{printf("-- [%d]: fd(%d) must be return %s >> %s\n",					i, fd[i], ret, s);	errors++;}; free(s);
	ret = "0123456789";
	s = get_next_line(fd[i]);
	if (s != NULL)
/* 6 */	{printf("-- [%d]: fd(%d) must be return %s >> %s\n",					i, fd[i], ret, s);	errors++;}	i++; free(s);

	fd[i] = open("mix_", O_RDONLY);
	ret = "0123456789\n";
	s = get_next_line(fd[i]);
	if (s == NULL || strcmp(ret, s) != 0)
/* 7 */	{printf("-- [%d]: fd(%d) must be return %s >> %s\n",					i, fd[i], ret, s);	errors++;}; free(s);
	ret = "\n";
	s = get_next_line(fd[i]);
	if (s == NULL || strcmp(ret, s) != 0)
/* 8 */	{printf("-- [%d]: fd(%d) must be return %s >> %s\n",					i, fd[i], ret, s);	errors++;}	i++; free(s);
	ret = "\n";
	s = get_next_line(fd[i]);
	if (s == NULL || strcmp(ret, s) != 0)
/* 8 */	{printf("-- [%d]: fd(%d) must be return %s >> %s\n",					i, fd[i], ret, s);	errors++;}	i++; free(s);
	ret = "\n";
	s = get_next_line(fd[i]);
	if (s == NULL || strcmp(ret, s) != 0)
/* 8 */	{printf("-- [%d]: fd(%d) must be return %s >> %s\n",					i, fd[i], ret, s);	errors++;}	i++; free(s);
 


	printf("\nTOTAL ERRORS : %d/%d\n", errors, i);
	return 0;
}
