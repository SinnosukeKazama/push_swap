/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:28:44 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 14:28:49 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*jointed_s;
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);
	const size_t	num_allocate = len_s1 + len_s2 + 1;

	if (!s1 || !s2)
		return (ft_calloc(1, sizeof(char)));
	jointed_s = (char *)ft_calloc(num_allocate, sizeof(char));
	if (jointed_s)
	{
		ft_strlcpy(jointed_s, s1, len_s1 + 1);
		ft_strlcpy(&jointed_s[len_s1], s2, len_s2 + 1);
		return (jointed_s);
	}
	return (NULL);
}
/*
FIX LOG:20251109
 If ft_strlen(); gets NULL, it returns 0.So line(18,19) has non crash.
 Than line(22,23) NULL check.that is separate work from above.
 Why is the NULL guard split into two like this,
 Reason1,Improvement readable.
 Reason2,Improvement of ft_strlen();`s usability.
*/
