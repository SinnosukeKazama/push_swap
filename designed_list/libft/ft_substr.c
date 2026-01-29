/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:32:03 by skazama           #+#    #+#             */
/*   Updated: 2025/11/04 03:40:18 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	i = 0;
	if (!s)
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s) - 1)
		start = ft_strlen(s);
	while (s[start + i] != '\0' && i < len)
		++i;
	subs = (char *)ft_calloc(i + 1, sizeof(char));
	if (subs)
	{
		ft_strlcpy(subs, &s[start], i + 1);
		return (subs);
	}
	return (NULL);
}
/*
value i = s's null or index of len

*/
