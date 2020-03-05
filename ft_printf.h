#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <math.h>

# define LL long long int
# define ULL unsigned long long int

typedef struct		s_type
{
	char		flag;
	int			width;
	int			precision;
	int			size;
	char		type;
	va_list		vl;
	unsigned	print;
	char		*types;
	char		*sizes;
	int			length;
}					t_type;

int				ft_print_int(t_type type, LL elem);
int				ft_print_float(float elem, t_type type);
int				ft_print_char(char elem, t_type type);
int				ft_print_string(char* elem, t_type type);
int				ft_print_pointer(void* elem, t_type type);
int				ft_int_specifier(t_type type, LL num);
int				ft_unsig_int_specifier(t_type type, ULL num);

#endif

// int		ft_printf(const char* format, ...) 
// {
// 	t_type	type;
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	va_start(type.vl, format);
// 	ft_create_typestruct(&type, format);
// 	while (format[i + j]) {
// 		if (format[i + j] == '%' && format[i + 1 + j] != '%') {
// 			++i;
// 			j += ft_parse_type(format + i + j, &type);
// 		}
// 		++i;
// 	}
// 	return (0);
// }