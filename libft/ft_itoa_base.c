#include "libft.h"

int     ft_intlen_base(LL_int value, int base)
{
    int i;

    i = 1;
    if (value < 0 && base == 10)
        i++;
    while (value /= base)
        i++;
    return (i);
}

char    print_nbr(int value)
{
    char *str;

    str = "0123456789ABCDEF";
    return (str[value]);
}

char    *ft_itoa_base(LL_int value, int base)
{
    char            *str;
    int             count;

    count = ft_intlen_base(value, base);
    str = malloc(sizeof(char) * (count + 1));
    value = value < 0 ? (value * -1) : value;
    base = (LL_int)base;
    str[count] = '\0';
    while (value > base)
    {
        str[--count] = print_nbr(value % base);
        value /= base;
    }
    str[--count] = print_nbr(value % base);
    if (count)
        str[--count] = '-';
    return (str);
}
