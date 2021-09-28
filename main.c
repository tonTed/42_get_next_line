#include "get_next_line.h"

#include <fcntl.h>



int main(int argc, char const *argv[])
{
    int fd1 = open("42", O_RDONLY);
    ft_get_next_line(fd1);
    return 0;
    close(fd1);
}
