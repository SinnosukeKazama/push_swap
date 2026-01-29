/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:31:06 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 14:31:14 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr_b;
	char	*ptr_l;

	ptr_b = (char *)big;
	ptr_l = (char *)little;
	if (little[0] == '\0')
		return (ptr_b);
	i = 0;
	while (i < len && ptr_b[i] != '\0')
	{
		j = 0;
		while (i + j < len && ptr_b[i + j] == ptr_l[j])
		{
			++j;
			if (ptr_l[j] == '\0' )
				return (&ptr_b[i]);
		}
		++i;
	}
	return (NULL);
}
