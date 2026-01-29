/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:15:48 by skazama           #+#    #+#             */
/*   Updated: 2025/12/20 17:16:39 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	count_digit(const int n, const unsigned int base)
{
	unsigned int	u_n;
	int				digit;

	u_n = ft_abs(n);
	digit = 1;
	while (u_n >= base)
	{
		u_n /= base;
		digit++;
	}
	return (digit);
}
