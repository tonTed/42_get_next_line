#include <stdio.h>
#include <stdlib.h>

void    print_adress(char *s)
{
    printf("Inside function: %p\n", s);
}

int main(void)
{
    char *s = malloc(10);
    
    printf("Before function: %p\n", s);
    print_adress(s);
    printf("After function: %p\n", s);
    return 0;
}
