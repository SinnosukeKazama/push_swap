/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:09:23 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 14:09:37 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	else
	{
		return (base * ft_power(base, exponent - 1));
	}
}

static long int	ft_nstr_to_lint(char *str, int len_from_str)
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

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (c);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			j;
	int			sign;
	char		*ptr;

	ptr = (char *)nptr;
	i = 0;
	while (ft_isspace(ptr[i]))
		++i;
	sign = 1;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign *= -1;
		++i;
	}
	if (ptr[i] < '0' && '9' < ptr[i])
		return (0);
	j = 0;
	while (ft_isdigit(ptr[i + j]))
		++j;
	return (ft_nstr_to_lint(&ptr[i], j) * sign);
}
