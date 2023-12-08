#include "simulation.h"

void    ft_putchar(const char c)
{
    write(1, &c, 1);
}

void    ft_putstr(const char *str)
{
    size_t i = 0;

    while (i < strlen(str))
        ft_putchar(str[i++]);
}

void    ft_putendl(const char *str)
{
    ft_putstr(str);
    ft_putchar('\n');
}
