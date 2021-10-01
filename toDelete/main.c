#include "../get_next_line.h"

#include <fcntl.h>

int main()
{
	int fd1 = open("toDelete/42", O_RDONLY);

	if (fd1 == -1)
		{puts("open() error"); return (1);}
	
	get_next_line(fd1);
	// get_next_line(fd1);

	if (close(fd1) == -1)
		{puts("close() error"); return (1);}

	return (0);
}
