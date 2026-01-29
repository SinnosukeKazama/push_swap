/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:20:12 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 14:21:12 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s = (const unsigned char *)s;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char)c)
			return ((void *)ptr_s + i);
		++i;
	}
	return (NULL);
}
