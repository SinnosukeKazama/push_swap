/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:27:22 by skazama           #+#    #+#             */
/*   Updated: 2025/11/04 03:39:11 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr_s;

	i = 0;
	ptr_s = (char *)s;
	while (1)
	{
		if (ptr_s[i] == (char)c)
			return (&ptr_s[i]);
		if (ptr_s[i] == '\0')
			break ;
		++i;
	}
	return (NULL);
}
