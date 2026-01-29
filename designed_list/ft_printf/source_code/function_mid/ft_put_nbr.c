/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:01:43 by skazama           #+#    #+#             */
/*   Updated: 2025/12/20 17:01:55 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_put_nbr(int n)
{
	const unsigned int	base = 10;
	int					len_print;
	long int			ln;

	ln = n;
	len_print = 0;
	if (ln < 0)
	{
		ln *= -1;
		len_print += ft_put_char('-');
	}
	if (ln < base)
	{
		ft_put_char((signed char)ln + '0');
	}
	else if (ln >= base)
	{
		ft_put_nbr(ln / base);
		ft_put_nbr(ln % base);
	}
	len_print += count_digit(n, base);
	return (len_print);
}
