/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:31:34 by skazama           #+#    #+#             */
/*   Updated: 2025/11/04 03:39:29 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_s;

	i = ft_strlen(s);
	ptr_s = (char *)s;
	while (1)
	{
		if (ptr_s[i] == (char)c)
			return (&ptr_s[i]);
		if (i == 0)
			break ;
		--i;
	}
	return (NULL);
}
