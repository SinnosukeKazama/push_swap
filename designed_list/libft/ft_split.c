/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:26:53 by skazama           #+#    #+#             */
/*   Updated: 2025/11/04 04:10:53 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlento(const char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		++i;
	return (i);
}

static char	**free_all(char **s, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(s[i]);
		++i;
	}
	free(s);
	return (NULL);
}

static size_t	ft_count_row(const char c, const char *s)
{
	size_t	i;
	size_t	row;
	int		isword;

	i = 0;
	row = 0;
	isword = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (isword == 0)
				++row;
			isword = 1;
		}
		else if (s[i] == c)
			isword = 0;
		++i;
	}
	return (row);
}

static char	**ft_makesubstr(char **s_spl, const char *ptr_s, char c, size_t row)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (ptr_s[i] != '\0' && j < row)
	{
		while (ptr_s[i] == c && ptr_s[i] != '\0')
			++i;
		s_spl[j] = ft_substr(&ptr_s[i], 0, ft_strlento(c, &ptr_s[i]));
		if (!s_spl[j])
			return (free_all(s_spl, j));
		i += ft_strlento(c, &ptr_s[i]);
		++j;
	}
	return (s_spl);
}

char	**ft_split(const char *s, char c)
{
	char	**s_spl;
	size_t	row;

	if (!s)
	{
		s_spl = (char **)ft_calloc(1, sizeof(char *));
		if (!s_spl)
			return (NULL);
		s_spl[0] = NULL;
		return (s_spl);
	}
	row = ft_count_row(c, s);
	s_spl = (char **)ft_calloc(row + 1, sizeof(char *));
	if (!s_spl)
		return (NULL);
	s_spl = ft_makesubstr(s_spl, s, c, row);
	if (!s_spl)
		return (NULL);
	return (s_spl);
}
/*
WORK FLOW:
1)count number of row.		->in ft_split.
2)allocate memory as (char **).	->in ft_split.
3)make and cpy the line.	->in ft_makesubstr.
-----------------------------------------------------------
TREE OF THE CALLING FUNCTONS:
ft_split();
	ft_skip_first();
	ft_count_row();
	ft_calloc();
	ft_makesubstr();
		ft_strlento();
		ft_substr();
*/
