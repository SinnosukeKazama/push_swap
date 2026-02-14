/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:15:47 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 20:03:39 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parse_stdio.h"//must be io -> input

static bool	is_contains_space(const char *p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		if (p[i] == ' ')
			return (true);
		++i;
	}
	return (false);
}
static void	wpjoin(char **dest, char **new)
{
	size_t	i;

	if (!dest || !new)
		return ;
	if (!(*new))
		return ;
	i = 0;
	while (dest[i] != NULL)
		++i;
	dest[i] = new[0];
}
static void	free_wp(char **p)
{

}
char	**parse_chr_array(size_t *num_elements, char **p)
{
	char	**rt;
	char	**tmp;
	if (is_contains_spase(p[i]))
	{
		tmp = ft_split(p[i], ' ');
		if (!tmp)
			return (free_wp(p[i]), free(p), NULL);
		wpjoin(rt, tmp);
	}
	else
		wpjoin(rt, &p[i]);
	*num_elemetns = wplen(rt);
	return (rt);
}
/*
//
#include <stdio.h>
int main(int ac, char **av)
{
	size_t i =0;
	while (av[i] != NULL)
	{
		printf("%s\n",av[i]);
		++i;
	}
}*/
