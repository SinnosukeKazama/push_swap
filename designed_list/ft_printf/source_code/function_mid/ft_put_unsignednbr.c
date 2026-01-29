/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsignednbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:28:34 by skazama           #+#    #+#             */
/*   Updated: 2025/12/20 17:09:07 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_put_unsignednbr(unsigned int un)
{
	const unsigned int	n_base = 10;

	if (un < n_base)
	{
		ft_put_char((signed char)un + '0');
	}
	else if (un >= n_base)
	{
		ft_put_unsignednbr(un / n_base);
		ft_put_unsignednbr(un % n_base);
	}
	return (count_digit_unsigned(un, n_base));
}
