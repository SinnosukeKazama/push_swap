/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:06:40 by skazama           #+#    #+#             */
/*   Updated: 2025/12/20 17:08:46 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	num_to_str(char *buf, uintptr_t un)
{
	const unsigned int	n_base = 16;
	const char			*format_hex_lower = "0123456789abcdef";
	int					len_buf;

	len_buf = 0;
	while (un > 0)
	{
		buf[len_buf] = format_hex_lower[un % n_base];
		un /= n_base;
		++len_buf;
	}
	return (len_buf);
}

static void	put_str_rev(char *buf, int len_buf)
{
	while (len_buf--)
		ft_put_char(buf[len_buf]);
}

int	ft_put_ptr(void *ptr)
{
	int			len_0x;
	int			len_buf;
	uintptr_t	un;
	char		buf[32];

	un = (uintptr_t)ptr;
	if (!un)
		return (ft_put_str("(nil)"));
	len_0x = ft_put_str("0x");
	len_buf = num_to_str(buf, un);
	put_str_rev(buf, len_buf);
	return (len_0x + len_buf);
}
