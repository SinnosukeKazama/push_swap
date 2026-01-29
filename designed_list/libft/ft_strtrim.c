/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:31:47 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 15:31:59 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i_f;
	unsigned int	i_r;

	if (!s1 || !set)
		return (ft_calloc(1, sizeof(char)));
	i_f = 0;
	i_r = ft_strlen(s1);
	while (s1[i_f] && ft_strchr(set, s1[i_f]))
		++i_f;
	while (i_r > i_f && ft_strchr(set, s1[i_r - 1]))
		--i_r;
	return (ft_substr(s1, i_f, i_r - i_f));
}
/*
s1 = "  !,,,A!BC,,,,"
set = " ,!"

s_retrun = "A!BC"

*/
