#include "ft_printf.h"

void	error(int x)
{
	if (x == 1)
		write(1, "Memory allocation error\n", 24);
	else if (x == 2)
		write(1, "Enter type\n", 11);
	exit(1);
}

void	ft_parse_size(const char *format, t_type *type)
{
	int		i;

	i = 0;
	if (format[i] == 'h' && format[i + 1] != 'h')
		type->size = 1;
	if (format[i] == 'h' && format[i + 1] == 'h')
		type->size = 2;
	if (format[i] == 'l' && format[i + 1] != 'l')
		type->size = 3;
	if (format[i] == 'l' && format[i + 1] == 'l')
		type->size = 4;
	if (format[i] == 'L')
		type->size = 5;
}

int		ft_skip_size(int size)
{
	int		i;

	i = 0;
	if (size == 2 || size == 4)
		i += 2;
	if ((size != 2 || size != 4) && size)
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

int		ft_modifier_processing(t_type *type, const char *format, int count_skip)
{
	int		val;

	if ((val = ft_atoi(&format[0])) != 0) //добавить *
	{
		type->width = val;
		count_skip = ft_intlen(type->width);
	}
	else if (format[0] == '.') {
		count_skip += ft_zero_skip(&format[1]);
		type->precision = ft_atoi(&(format[1]));
		count_skip += ft_intlen(type->precision);
	}
	else
	{
		val = 0;
		while (format[0] != type->sizes[val] && type->sizes[val])
			val++;
		if (type->sizes[val] != '\0')
			ft_parse_size(&format[0], type);
		count_skip = ft_skip_size(type->size);
	}
	return (count_skip);
}

int		ft_parse_format(const char *format, t_type *type)
{
	int		i;
	int		count_skip;

	i = 0;
	count_skip = 1;
	if ((format[i] == '+' || format[i] == '-' || format[i] == ' '
	|| format[i] == '#' || format[i] == '0') && type->flag == '%')
		type->flag = format[i];
	else if (format[i] != '0')
		return (ft_modifier_processing(type, format, count_skip));
	return (count_skip);
}

int		ft_parse_type(const char *format, t_type *type)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (format[i] && format[i] != type->types[j])
	{
		while (type->types[j] && format[i] != type->types[j])
			j++;
		if (type->types[j] == '\0')
		{
			j = 0;
			i += ft_parse_format(&format[i], type);
		}
	}
	if (format[i] == type->types[j])
	{
		type->type = type->types[j];
		return (i);
	}
	else
		error(2);
	return (0);
}

void	ft_type_cleaning(t_type *type)
{
	type->flag = '%';
	type->width = 0;
	type->precision = 0;
	type->size = 0;
	type->type = '0';
	type->length = 0;
}

void	ft_create_typestruct(t_type *type)
{
	type->types = "diuoxXfcspeg";
	type->sizes = "hlL";
	ft_type_cleaning(type);
	type->print = 0;
}

void	ft_print_format(t_type *type)
{
	if (type->type == 'd' || type->type == 'i')
		type->print += ft_int_specifier(*type, va_arg(type->vl, LL));
	// else if (type->type == 'o' || type->type == 'u'
	// || type->type == 'x' || type->type == 'X')
	// 	type->print += ft_unsig_int_specifier(*type, va_arg(type->vl, ULL));
	else if (type->type == 'f' || type->type == 'e' || type->type == 'g')
		type->print += ft_print_float(va_arg(type->vl, double), *type);
	else if (type->type == 'c')
		type->print += ft_print_char(va_arg(type->vl, int), *type);
	else if (type->type == 's')
		type->print += ft_print_string(va_arg(type->vl, char*), *type);
	else if (type->type == 'p')
		type->print += ft_print_pointer(va_arg(type->vl, void*), *type);
}

int		ft_printf(const char *format, ...)
{
	t_type	type;
	int		i;

	i = -1;
	va_start(type.vl, format);
	ft_create_typestruct(&type);
	while (format[++i])
		if (format[i] == '%' && format[i + 1] != '%')
		{
			++i;
			i += ft_parse_type(&format[i], &type);
			ft_print_format(&type);
			ft_type_cleaning(&type);
		}
		else
		{
			write(1, &format[i], 1);
			type.print++;
		}
	va_end(type.vl);
	return (type.print);
}

int		main()
{
	char	*types;
	int		c;

	c = 1;
	types = "abcdefghijkl";
	// int *t = &c;
	// printf("test1 %d\n", ft_printf("%-3.5d %d %d\n", 123, 12, 13));
	// printf("test1 %d\n", printf("%-3.5d %d %d\n", 123, 12, 13));
	// printf("test2 %d\n", ft_printf("%-7.5d\n", -1234567));
	printf("test2 %d\n", ft_printf("%-7.5d\n", -1234567));
	// printf("%d\n", ft_printf("print %-0006.05s, %0006s\n", types, types));
	// printf("%d\n", printf("print %-0006.05s, %0006s\n", types, types));
	// printf("%d\n", ft_printf("%0002.6d\n", (short)-120000));
	// printf("%d\n", printf("%0002.6d\n", (short)-120000));
	// printf("%10.0006s", types);
	return (0);
}
