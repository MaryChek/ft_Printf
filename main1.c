#include "ft_printf.h"
#include <limits.h>

void	error(int x, va_list vl)
{
	if (x == 1)
		write(1, "Memory allocation error\n", 24);
	else if (x == 2)
		write(1, "", 1);
	va_end(vl);
	exit(1);
}

void	ft_type_cleaning(t_type *type)
{
	type->flag = '%';
	type->width = 0;
	type->precision = -1;
	type->size = 0;
	type->type = '0';
	type->length = 0;
}

void	ft_create_typestruct(t_type *type)
{
	type->types = "diuoxXfcspeg\0";
	type->sizes = "hlL\0";
	ft_type_cleaning(type);
	type->print = 0;
}

void	ft_print_format(t_type *type)
{
	if (type->type == 'd' || type->type == 'i')
		type->print += ft_int_specifier(*type, va_arg(type->vl, LL_int));
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
			if (format[i] == '%' && format[i + 1])
				i++;
			write(1, &format[i], 1);
			type.print++;
		}
	va_end(type.vl);
	return (type.print);
}

void	test_int(char *str, int64_t num)
{
	int a, b;
	a = printf(str, num);
	printf("print =       ");
	printf("%d\n", a);
	b = ft_printf(str, num);
	printf("my print =    ");
	printf("%d\n\n", b);
}
void	test_int_arg(int64_t num)
{
	// test_int("--->_%-7li\n", num);
	// test_int("--->_%-7.li\n", num);
	// test_int("--->_%-7.10li\n", num);
	// test_int("--->_%-7.6li\n", num);

	// test_int("--->_%7li\n", num);
	// test_int("--->_%7.li\n", num);
	// test_int("--->_%7.10li\n", num);
	// test_int("--->_%7.6li\n", num);

	// test_int("--->_%07li\n", num);
	// test_int("--->_%07.li\n", num);
	// test_int("--->_%07.10li\n", num);
	// test_int("--->_%07.6li\n", num);
	
	test_int("--->_%+7li\n", num);
	// test_int("--->_%+7.li\n", num);
	test_int("--->_%+7.10li\n", num);
	test_int("--->_%+7.6li\n", num);
}

int		main()
{
	// char	*types;
	// char	c;

	// c = '0';
	// types = "abcdefghijkl";
	// static char *s_hidden = "hi low\0don't print me lol\0";
	// int *t = &c;
	// printf("test1 %d\n", ft_printf("%-7i", 0));

	test_int_arg(-65324559656);

	// printf("test my %d\n", ft_printf("%02.0010c\n", 'c'));
	// printf("test my %d\n", printf("%02.0010c\n", 'c'));
	// printf("test2 %d\n", ft_printf("%-7.5d\n", -1234567));
	// printf("test2 %d\n", ft_printf("%d\n", H));
	// printf("%d\n", ft_printf("print %-0006.05s, %0006s\n", types, types));
	// ft_printf("%5%");
	// printf("% d\n", printf("%5%"));
	// printf("%d\n", ft_printf("%5%3%4%4%2%"));
	// printf("%d\n", printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c"));
	// printf("%d\n", ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c"));
	// printf("%10.0006s", types);
	return (0);
}