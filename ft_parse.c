#include "ft_printf.h"

void	ft_parse_size(const char *format, t_type *type)
{
	if (format[0] == 'h' && format[1] != 'h')
		type->size = H;
	if (format[0] == 'h' && format[1] == 'h')
		type->size = HH;
	if (format[0] == 'l' && format[1] != 'l')
		type->size = L;
	if (format[0] == 'l' && format[1] == 'l')
		type->size = LL;
	if (format[0] == 'L')
		type->size = L_big;
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
		if (type->precision != 0)
			count_skip += ft_intlen(type->precision);
	}

	else
	{
		val = 0;
		while (format[0] != type->sizes[val] && type->sizes[val])
			++val;
		if (type->sizes[val] != '\0')
			ft_parse_size(&format[0], type);
		count_skip += ft_skip_size(type->size);
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
		error(2, type->vl);
	return (0);
}
