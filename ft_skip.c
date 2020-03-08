#include "ft_printf.h"

int		ft_skip_size(int size)
{
	int		i;

	i = 0;
	if (size == HH || size == LL)
		++i;
	return (i);
}

int		ft_zero_skip(const char *format)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i++] == '0')
		count++;
	return (count);
}

