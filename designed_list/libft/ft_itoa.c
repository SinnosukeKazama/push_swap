/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:13:03 by skazama           #+#    #+#             */
/*   Updated: 2025/11/01 21:04:36 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static signed char	ft_is_sign(int *ptr_n)
{
	if (*ptr_n < 0)
	{
		*ptr_n *= -1;
		return (-1);
	}
	else
		return (1);
}

static size_t	ft_count_digit(unsigned int n)
{
	size_t	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static char	*ft_numstr(char *ptr, unsigned int n, size_t digit,
		const int pos_or_neg)
{
	if (pos_or_neg == -1)
		ptr[0] = '-';
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		if (pos_or_neg == -1)
			ptr[digit] = n % 10 + '0';
		else
			ptr[digit - 1] = n % 10 + '0';
		n /= 10;
		--digit;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char				*ptr;
	size_t				digit;
	const signed char	pos_or_neg = ft_is_sign(&n);

	digit = ft_count_digit((unsigned int)n);
	if (pos_or_neg == -1)
		ptr = (char *)ft_calloc(digit + 2, sizeof(char));
	else
		ptr = (char *)ft_calloc(digit + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_numstr(ptr, (unsigned int)n, digit, pos_or_neg);
	return (ptr);
}
