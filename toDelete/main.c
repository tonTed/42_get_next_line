#include "../get_next_line.h"

#include <fcntl.h>

int main()
{
	// if (argc != 2)
	// 	return 0;
	// int fd1 = open(argv[1], O_RDONLY);

	int fd1 = open("toDelete/42", O_RDONLY);

	
	if (fd1 == -1)
		{puts("open() error");return (1);}
	
	char	*s;
	while ((s = get_next_line(fd1)))
		{
			printf("%s\n", s);
			// sleep(1);
		}

	
	if (close(fd1) == -1)
		{puts("close() error");return (1);}

	return (0);
}
