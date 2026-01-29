/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:30:23 by skazama           #+#    #+#             */
/*   Updated: 2025/11/04 00:45:32 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr_new;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	ptr_new = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr_new)
		return (NULL);
	while (i < len)
	{
		ptr_new[i] = f(i, s[i]);
		++i;
	}
	return (ptr_new);
}
// test strmapi
/*
static size_t	f3_len(const char *s)
{
	return (ft_strlen(s));
}

static char	f2_up_or_low(unsigned int index, char c)
{
	if (index % 2 == 0)
		return ((char)ft_tolower((signed char)c));
	else
		return ((char)ft_toupper((signed char)c));
}

static char	f2_oneplus_alphabet_to50(unsigned int index, char c)
{
	if (index < 50)
		return (c+1);
	else
		return (c);
}
int	main(void)
{

	//size_t (*ptr_f)(const char *);
	char (*ptr_f2)(unsigned int, char);
	char *(*ptr_f)(char const *, char (*f)(unsigned int, char));
	//ptr_f = f_len;
	ptr_f2 = f2_up_or_low;
	ptr_f = ft_strmapi;

	const char s[] = "You can pack up a";
	char *ptr_new = ptr_f(s, ptr_f2);
	ptr_f2 = f2_oneplus_alphabet_to50;
	char *ptr_new2 = ptr_f(s, ptr_f2);
	if (ptr_new)
	{
		printf("s  :%s\nnew:%s\n", s, ptr_new);
		printf("s  :%s\nnew:%s\n", s, ptr_new2);
		free(ptr_new);
	}
	return (0);
}*/
