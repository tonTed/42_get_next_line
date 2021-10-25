#include <stdio.h>
#include <stdlib.h>

void    print_adress(char *s, char **m)
{
    // printf("Inside function: %p\n", s);
    printf("Inside function m: %p\n", m);
    printf("Inside function *m: %p\n", *m);

    *m = malloc(10);

    printf("Inside function finish m: %p\n", m);
    printf("Inside function finish *m: %p\n", *m);
}

int main(void)
{
    char *s = malloc(10);
    char *m;
    
    // printf("Before function s: %p\n", s);
    printf("Before function &m: %p\n", &m);
    printf("Before function m: %p\n", m);
    print_adress(s, &m);
    // printf("After function s: %p\n", s);
    printf("After function &m: %p\n", &m);
    printf("After function m: %p\n", m);

    return 0;
}
