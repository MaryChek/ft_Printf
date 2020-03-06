#include "ft_printf.h"

int		print_n_char(int num, char c)
{
	int count;

	count = num; 
	while (num-- > 0)
		write(1, &c, 1);
	return (count);
}

int		print_spase(t_type type)
{
	int i;
	int count;
	char c;

	count = 0;
	if (type.precision > type.length)
		i = type.width - type.precision;
	else
		i = type.width - type.length;
	if (i > 0)
	{
		c = type.precision < 0 ? '0' : ' ';
		count = print_n_char(i, c);
	}
	return (count);
}

int		print_precision(t_type type)
{
	int i;
	int count;

	count = 0;
	i = type.precision - type.length;
	if (i > 0 )
		count = print_n_char(i, '0');
	return (count);
}

int		ft_print_int(t_type type, LL_int elem)
{
	int count;
	int i;

	count = 0;
	type.length = ft_intlen(elem);
	if (type.flag == '-')
	{
		count += print_precision(type);
		ft_putstr(ft_itoa_base(elem, 10));
		count += print_spase(type);
	}
	else
	{
		count += print_spase(type);
		count += print_precision(type);
		ft_putstr(ft_itoa_base(elem, 10));
	}
	return (count + type.length);
}
int		ft_print_float(float elem, t_type type)
{

}
int		ft_print_char(char elem, t_type type)
{
	if (type.width)
	{
		if (type.flag == '0')
		{
			print_n_char(type.width - 1, '0');
			write(1, &elem, 1);
		}
		else if (type.flag == '-')
		{
			write(1, &elem, 1);
			print_n_char(type.width - 1, ' ');
		}
	}
	else
	{
		ft_putchar(elem);
		return (1);
	}
	return (type.width);
}

int		ft_put_space(char* elem, t_type type)
{
	int stlen;
	char c;
	int count;

	count = 0;
	if (type.width > 0 && type.width > (stlen = ft_strlen(elem)))
	{
		c = (type.flag == '0') ? '0' : ' ';
		while (stlen++ < type.width)
		{
			write(1, &c, 1);
			count++;
		}
	}
	count += ft_strlen(elem);
	return (count);
}

int		ft_print_string(char* elem, t_type type)
{
	int count;
	char *str;

	count = 0;
	if (elem != NULL)
		str = type.precision >= 0 ? ft_strsub(elem, 0, type.precision) : elem;
	else 
		str = type.precision >= 0 ? ft_strsub("(null)\0", 0, type.precision) : "(null)\0";
	if (type.flag == '-')
	{
		ft_putstr(str);
		count += ft_put_space(str, type);
	}
	else
	{
		count += ft_put_space(str, type);
		ft_putstr(str);
	}
	(type.precision >= 0 && elem != NULL) ? ft_strdel(&str) : 0;
	return (count);
}

int		ft_print_pointer(void* elem, t_type type)
{

}

int		ft_int_specifier(t_type type, LL_int elem)
{
	if (type.size == H) // h
		return (ft_print_int(type, (short)elem));
	else if (type.size == HH)
		return (ft_print_int(type, (char)elem));
	else if (type.size == L || type.size == LL)
		return (ft_print_int(type, (long int)elem));
	else
		return (ft_print_int(type, (int)elem));
}