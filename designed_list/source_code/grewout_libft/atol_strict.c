/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:09:23 by skazama           #+#    #+#             */
/*   Updated: 2026/02/09 14:09:26 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grewout_libft.h"

static int	ft_power(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	else
	{
		return (base * ft_power(base, exponent - 1));
	}
}

static long int	ft_nstr_to_lint(const char *str, int len_from_str)
{
	int			len;
	long int	sum;
	int			exp;

	sum = 0;
	exp = 0;
	len = len_from_str;
	while (0 < len)
	{
		sum += ft_power(10, exp) * (str[len - 1] - '0');
		++exp;
		--len;
	}
	return (sum);
}
bool	atol_strict(long int *dest, const char *nptr)
{
	int			i;
	int			j;
	int			sign;

	i = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		++i;
	}
	if (nptr[i] < '0' || '9' < nptr[i])
		return (false);
	j = 0;
	while (ft_isdigit(nptr[i + j]))
		++j;
	if (nptr[i + j] != '\0')
		return (false);
	*dest = ft_nstr_to_lint(&nptr[i], j) * sign;
	return (true);
}
/*
#include <stdio.h>
int main(void)
{
	char *a = "+1a";
	long int la = 0;
	printf("bool=%i\n",atol_strict(&la, a));
	printf("char=%s -> int=%li\n", a, la);
}*/
