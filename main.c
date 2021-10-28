/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:38:37 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/27 22:38:25 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include "ft_color.h"
#include <limits.h>

int	ft_test_ft_strndup(int *test)
{
	int errors = 0;
	char	*expected;
	char	*returned;
	char	*s;
	int inter_tests = *test;

	printf(MAG "\n----- FT_STRNDUP:" reset);
	// 1
	(*test)++;
	returned = ft_strndup(NULL, 3);
	expected = "";
	if (strcmp(expected, returned))
		{printf(YEL "\n1_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 2
	(*test)++;
	returned = ft_strndup(NULL, 0);
	expected = "";
	if (strcmp(expected, returned))
		{printf(YEL "\n2_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 3
	(*test)++;
	returned = ft_strndup("42 Quebec", 0);
	expected = "";
	if (strcmp(expected, returned))
		{printf(YEL "\n3_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 4
	(*test)++;
	returned = ft_strndup("42 Quebec", 2);
	expected = "42";
	if (strcmp(expected, returned))
		{printf(YEL "\n4_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 5
	(*test)++;
	returned = ft_strndup("42 Quebec", 9);
	expected = "42 Quebec";
	if (strcmp(expected, returned))
		{printf(YEL "\n5_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	
	//END
	if (errors)
		printf(RED "\nErrors: %d/%d\n" reset,errors, *test - inter_tests);
	else
		printf(GRN " PASSED" reset);
	return (errors);
}

int	ft_test_ft_freejoin(int *test)
{
	int errors = 0;
	char	*expected;
	char	*returned;
	char	*s;
	int inter_tests = *test;

	printf(MAG "\n----- FT_FREEJOIN:" reset);
	// 1
	(*test)++;
	returned = ft_freejoin(NULL, NULL);
	expected = "";
	if (strcmp(expected, returned))
		{printf(YEL "\n1_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 2
	(*test)++;
	returned = ft_freejoin(NULL, "42");
	expected = "42";
	if (strcmp(expected, returned))
		{printf(YEL "\n2_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 3
	(*test)++;
	s = strdup("42 Quebec");
	returned = ft_freejoin(s, " 42");
	expected = "42 Quebec 42";
	if (strcmp(expected, returned))
		{printf(YEL "\n3_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 4
	(*test)++;
	s = strdup("");
	returned = ft_freejoin(s, "42");
	expected = "42";
	if (strcmp(expected, returned))
		{printf(YEL "\n4_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	// 5
	(*test)++;
	s = strdup("");
	returned = ft_freejoin(s, "");
	expected = "";
	if (strcmp(expected, returned))
		{printf(YEL "\n5_\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	
	//END
	if (errors)
		printf(RED "\nErrors: %d/%d\n" reset,errors, *test - inter_tests);
	else
		printf(GRN " PASSED" reset);
	return (errors);
}

int	ft_test_ft_strlen(int *test)
{
	int errors = 0;
	int expected;
	int returned;
	int inter_tests = *test;

	printf(MAG "\n----- FT_STRLEN:" reset);
	// 1
	(*test)++;
	returned = ft_strlen(NULL);
	expected = 0;
	if (returned != expected)
		{printf(YEL "\n1_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 2
	(*test)++;
	returned = ft_strlen("0123456789");
	expected = 10;
	if (returned != expected)
		{printf(YEL "\n2_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 3
	(*test)++;
	returned = ft_strlen("Sch\0ol42");
	expected = 3;
	if (returned != expected)
		{printf(YEL "\n3_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	(*test)++;
	// 4
	returned = ft_strlen(".....");
	expected = 5;
	if (returned != expected)
		{printf(YEL "\n4_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 5
	returned = ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	expected = 445;
	if (returned != expected)
		{printf(YEL "\n5_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	
	//END
	if (errors)
		printf(RED "\nErrors: %d/%d\n" reset,errors, *test - inter_tests);
	else
		printf(GRN " PASSED" reset);
	return (errors);
}

int	ft_test_ft_charinstr(int *test)
{
	int errors = 0;
	int expected;
	int returned;
	int inter_tests = *test;

	printf(MAG "\n----- FT_CHARINSTR:" reset);
	// 1
	(*test)++;
	returned = ft_charinstr(NULL, '\0');
	expected = -1;
	if (returned != expected)
		{printf(YEL "\n1_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 2
	(*test)++;
	returned = ft_charinstr(NULL, '$');
	expected = -1;
	if (returned != expected)
		{printf(YEL "\n2_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 3
	(*test)++;
	returned = ft_charinstr("42 Quebec", '$');
	expected = -1;
	if (returned != expected)
		{printf(YEL "\n3_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	(*test)++;
	// 4
	returned = ft_charinstr("$", '$');
	expected = 0;
	if (returned != expected)
		{printf(YEL "\n4_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 5
	returned = ft_charinstr("42 Quebec", ' ');
	expected = 2;
	if (returned != expected)
		{printf(YEL "\n5_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 6
	returned = ft_charinstr("42 Quebec#", '#');
	expected = 9;
	if (returned != expected)
		{printf(YEL "\n6_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 7
	returned = ft_charinstr("###########", '#');
	expected = 0;
	if (returned != expected)
		{printf(YEL "\n7_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	// 8
	returned = ft_charinstr("42 Quebec####", '#');
	expected = 9;
	if (returned != expected)
		{printf(YEL "\n8_\texpected: %d\t - returned: %d" reset, expected, returned); errors++;}
	
	//END
	if (errors)
		printf(RED "\nErrors: %d/%d\n" reset,errors, *test - inter_tests);
	else
		printf(GRN " PASSED" reset);
	return (errors);
}

void	ft_test_gnl(void)
{
	int		errors = 0;
	int		tests = 0;
	int		fd;
	char	*expected;
	char	*returned;

	
	printf(BBLU "\n----- GET_NEXT_LINE:" reset);

	//__1
	tests++;
	returned = get_next_line(-1);
	expected = NULL;
	if (returned != NULL || expected != NULL)
		{printf(YEL "\n__1\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	//__2
	tests++;
	returned = get_next_line(OPEN_MAX + 1);
	expected = NULL;
	if (returned != NULL || expected != NULL)
		{printf(YEL "\n__2\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	//__3__a
	tests++;
	fd = open("files/test", O_RDONLY);
	returned = get_next_line(fd);
	expected = "42 Quebec\n";
	if (!returned || strcmp(returned, expected))
		{printf(YEL "\n__3__a\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	//__3__b
	tests++;
	returned = get_next_line(fd);
	expected = "Ubisoft\n";
	if (!returned || strcmp(returned, expected))
		{printf(YEL "\n__3__b\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	//__3__c
	tests++;
	returned = get_next_line(fd);
	expected = "\n";
	if (!returned || strcmp(returned, expected))
		{printf(YEL "\n__3__c\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	//__3__d
	tests++;
	returned = get_next_line(fd);
	expected = NULL;
	if (returned != NULL || expected != NULL)
		{printf(YEL "\n__3__d\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	//__4
	tests++;
	fd = open("files/empty", O_RDONLY);
	returned = get_next_line(fd);
	expected = NULL;
	if (returned != NULL || expected != NULL)
		{printf(YEL "\n__4\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	close(fd);
	//__5__a
	tests++;
	fd = open("files/only_nl", O_RDONLY);
	returned = get_next_line(fd);
	expected = "\n";
	if (!returned || strcmp(returned, expected))
		{printf(YEL "\n__5__a\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	//__5__b
	tests++;
	returned = get_next_line(fd);
	expected = "\n";
	if (!returned || strcmp(returned, expected))
		{printf(YEL "\n__5__b\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	//__5__c
	tests++;
	returned = get_next_line(fd);
	expected = "\n";
	if (!returned || strcmp(returned, expected))
		{printf(YEL "\n__5__c\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	//__5__d
	tests++;
	returned = get_next_line(fd);
	expected = "\n";
	if (!returned || strcmp(returned, expected))
		{printf(YEL "\n__5__d\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	//__5__e
	tests++;
	returned = get_next_line(fd);
	expected = NULL;
	if (returned != NULL || expected != NULL)
		{printf(YEL "\n__5__e\texpected: %s\t - returned: %s" reset, expected, returned); errors++;}
	free(returned);
	close(fd);

	puts("\n\n----- RESULT -----");
	if (errors)
		printf(BRED "TOTAL ERRORS: %d/%d\n" reset, errors, tests);
	else
		printf(BGRN "PASSED\n" reset);
}

int main()
{
	int	test = 0;
	int errors = 0;

	errors += ft_test_ft_charinstr(&test);
	errors += ft_test_ft_strlen(&test);
	errors += ft_test_ft_freejoin(&test);
	errors += ft_test_ft_strndup(&test);

	puts("\n\n----- RESULT -----");
	if (errors)
		printf(BRED "TOTAL ERRORS: %d/%d\n" reset, errors, test);
	else
		printf(BGRN "PASSED\n" reset);

	if (!errors)
		ft_test_gnl();
	else
		printf(RED "\nFIX FUNCTIONS BEFORE TEST GNL" reset);
	return 0;
}

