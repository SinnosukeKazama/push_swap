/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:10:17 by skazama           #+#    #+#             */
/*   Updated: 2025/11/01 21:03:50 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	size_allocate;

	if (size != 0 && nmemb != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	size_allocate = size * nmemb;
	ptr = malloc(size_allocate);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size_allocate);
	return (ptr);
}
