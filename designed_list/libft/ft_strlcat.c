/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:29:07 by skazama           #+#    #+#             */
/*   Updated: 2025/11/09 13:04:56 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dest_len = ft_strlen(dest);
	const size_t	src_len = ft_strlen(src);
	size_t			i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] != '\0' && i < size - dest_len - 1)
	{
		dest[dest_len + i] = src[i];
		++i;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
dest.."abc" .3
src..."ABC".3
size..9

(i < size - dest_len - 1)
5-3-1=1 ->
7-3-1=3
9-3-1=5

*/
