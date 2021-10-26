#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line.h"

void	print_adress(char *s, char **m)
{
	// printf("Inside function: %p\n", s);
	char *l;
	l = NULL;

	printf("Inside function &l: %p\n", &l);
	printf("Inside function l: %p\n", l);
	printf("Inside function c l: %c\n", *l);
	printf("Inside function m: %p\n", m);
	printf("Inside function *m: %p\n", *m);

	*m = malloc(10);

	printf("Inside function finish m: %p\n", m);
	printf("Inside function finish *m: %p\n", *m);
}

void	static_test2(char **save)
{
	printf("2_\t address save: %p\t value: %s\t address &save:%p\n", *save, *save, save);
	*save = "0987654321\0";
	printf("3_\t address save: %p\t value: %s\t address &save:%p\n", *save, *save, save);
}

void	static_test(void)
{
	static char *save = NULL;
	if (save)
		printf("_\t address save: %p\t value: %s\t address &save:%p\n", save, save, &save);
	printf("0_\t address save: %p\t value: %s\t address &save:%p\n", save, save, &save);
	save = malloc(11);
	save = "1234567890\0";
	printf("1_\t address save: %p\t value: %s\t address &save:%p\n", save, save, &save);
	static_test2(&save);
	printf("4_\t address save: %p\t value: %s\t address &save:%p\n", save, save, &save);

}

int main(void)
{
	// char *s = malloc(10);
	// char *m;
	
	// // printf("Before function s: %p\n", s);
	// printf("Before function &m: %p\n", &m);
	// printf("Before function m: %p\n", m);
	// print_adress(s, &m);
	// // printf("After function s: %p\n", s);
	// printf("After function &m: %p\n", &m);
	// printf("After function m: %p\n", m);

	// char *s;

	// int fd = open("get_next_line_utils.c", O_RDONLY);
	// if (fd < 0){puts("error open()");}
	
	// while ((s = get_next_line(fd)))
	// 	printf("%s\n", s);
	// printf("%s\n", s);

	static_test();
	static_test();

	return 0;
}
