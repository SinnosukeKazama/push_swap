/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:35:31 by skazama           #+#    #+#             */
/*   Updated: 2026/01/04 05:00:10 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	print_conversion_format(va_list args, const char type)
{
	int	len_count;

	len_count = 0;
	if (type == 'd' || type == 'i')
		len_count += ft_put_nbr(va_arg(args, int));
	else if (type == 'u')
		len_count += ft_put_unsignednbr(va_arg(args, unsigned int));
	else if (type == 'x')
		len_count += ft_put_hexadecimal(va_arg(args, unsigned int), lower);
	else if (type == 'X')
		len_count += ft_put_hexadecimal(va_arg(args, unsigned int), upper);
	else if (type == 'p')
		len_count += ft_put_ptr(va_arg(args, void *));
	else if (type == 'c')
		len_count += ft_put_char(va_arg(args, int));
	else if (type == 's')
		len_count += ft_put_str(va_arg(args, char *));
	else if (type == '%')
		len_count += ft_put_char(type);
	else
		return (ERROR_FORMAT);
	return (len_count);
}

static int	print_loop(va_list args, const char *format)
{
	size_t	i;
	int		len_count;
	int		rt;

	i = 0;
	len_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (ERROR_FORMAT);
			rt = print_conversion_format(args, format[++i]);
			if (rt == ERROR_FORMAT)
				return (ERROR_FORMAT);
			len_count += rt;
		}
		else
			len_count += ft_put_char(format[i]);
		++i;
	}
	return (len_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	if (!format)
		return (ERROR_FORMAT);
	va_start(args, format);
	return (va_end(args), print_loop(args, format));
}
