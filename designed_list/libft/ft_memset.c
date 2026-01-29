/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:23:20 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 14:23:32 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned int	i;

	ptr_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr_s[i] = c;
		++i;
	}
	return (s);
}
