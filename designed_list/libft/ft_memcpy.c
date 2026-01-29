/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:21:51 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 14:21:56 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s = (const unsigned char *)src;
	unsigned int		i;

	ptr_d = (unsigned char *)dest;
	i = 0;
	if (ptr_s == ptr_d)
		return (dest);
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		++i;
	}
	return (dest);
}
