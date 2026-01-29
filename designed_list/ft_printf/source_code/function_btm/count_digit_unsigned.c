/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:14:44 by skazama           #+#    #+#             */
/*   Updated: 2025/12/20 17:16:11 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	count_digit_unsigned(unsigned int un, const unsigned int base)
{
	int	digit;

	digit = 1;
	while (un >= base)
	{
		un /= base;
		digit++;
	}
	return (digit);
}
