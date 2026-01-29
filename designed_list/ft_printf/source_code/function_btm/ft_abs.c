/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:18:47 by skazama           #+#    #+#             */
/*   Updated: 2025/12/10 16:19:34 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

unsigned int	ft_abs(const int n)
{
	if (n < 0)
		return ((unsigned int)(-(long long)n));
	else
		return ((unsigned int)n);
}
