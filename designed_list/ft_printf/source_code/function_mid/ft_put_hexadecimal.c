/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:45:06 by skazama           #+#    #+#             */
/*   Updated: 2025/12/20 17:03:51 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_put_hexadecimal(unsigned int un, const bool letter_case)
{
	const char			*format_hex_lower = "0123456789abcdef";
	const char			*format_hex_upper = "0123456789ABCDEF";
	const unsigned int	n_base = 16;

	if (un < n_base)
	{
		if (letter_case == lower)
			ft_put_char(format_hex_lower[un]);
		else if (letter_case == upper)
			ft_put_char(format_hex_upper[un]);
	}
	else if (un >= n_base)
	{
		ft_put_hexadecimal(un / n_base, letter_case);
		ft_put_hexadecimal(un % n_base, letter_case);
	}
	return (count_digit_unsigned(un, n_base));
}
