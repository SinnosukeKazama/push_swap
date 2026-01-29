/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:22:09 by skazama           #+#    #+#             */
/*   Updated: 2025/11/04 02:31:27 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_s = (const unsigned char *)src;
	unsigned char		*ptr_d;
	size_t				i;

	ptr_d = (unsigned char *)dest;
	if (ptr_s == ptr_d)
		return (dest);
	if (ptr_d > ptr_s)
	{
		i = n + 1;
		while (--i > 0)
			ptr_d[i - 1] = ptr_s[i - 1];
	}
	else
	{
		i = -1;
		while (++i < n)
			ptr_d[i] = ptr_s[i];
	}
	return (dest);
}
