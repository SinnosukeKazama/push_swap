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
	while (p[i] != '\0')
	{
		if (p[i] == ' ')
			return (true);
		++i;
	}
	return (false);
}
static size_t	wplen(char **p)
{
	size_t	i;

	i = 0;
	while (p[i] != NULL)
		++i;
	return (i);
}
static char	**wpjoin(char **a, char **b)
{
	size_t	i;
	size_t	j;
	char **p;
	const size_t	num_a = wplen(a);
	const size_t	num_b = wplen(b);
	if (!a || !b)
		return (NULL);
	if (!(*b))
		return (NULL);
	p = malloc(sizeof(char*) * (num_a + num_b));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < num_a)
		p[i] = a[i];
	j = -1;
	while (++j < num_b)
		p[i + j] = b[j];
	return (p);
}
char	**append(char **ptr, char *src)
{
	const size_t	size_ptr = wplen(ptr);
	const size_t	size_new = size_ptr + 2;
	char	**ptr_new;
	size_t	i;

	ptr_new = malloc(sizeof(char *) * size_new);
	if (!ptr_new)
		return (NULL);
	i = -1;
	while (++i < size_ptr)
		ptr_new[i] = ptr[i];
	ptr_new[i] = src;
	ptr_new[i + 1] = NULL;
	return (ptr_new);
}
//this function DOES NOT copy char, just copy ptr.
char	**divide_spc(char **rt, char *p)
{
	char	**rt_new;
	char	**tmp;
	size_t	i;

	tmp = ft_split(p, ' ');
	if (!tmp)
		return (free_wp(rt), NULL);
	i = 0;
	while (tmp[i] != NULL)
	{
		rt_new = append(rt, tmp[i]);
		if (!rt_new)
			return (free_wp(rt), free(tmp), NULL);
		free(rt);
		rt = rt_new;
		++i;
	}
	free(tmp);
	return (rt);
}
#include <stdio.h>
char	**parse_chr_array(size_t *num_elements, char **p)
{
	char	**rt;
	char	**rt_new;
	char	*dup;
	size_t	i;

	rt = malloc(sizeof(char*));
	if (!rt)
		return (NULL);
	rt[0] = NULL;
	i = 0;
	while (p[i] != NULL) 
	{
		if (is_contains_space(p[i]))
		{
			rt = divide_spc(rt, p[i]);
			if (!rt)
				return (NULL);
		}
		else
		{
			dup = ft_strdup(p[i]);
			if (!dup)
				return (free_wp(rt), NULL);
			rt_new = append(rt, dup);
			if (!rt_new)
				return (free(dup), free_wp(rt), NULL);
			free(rt);
			rt = rt_new;
		}
		++i;
	}
	*num_elements = wplen(rt);
	return (rt);
}

/*
int main(int ac, char **av)
{
	size_t i =0;
	size_t	num_elements = (size_t)ac - 1;

	char **p = parse_chr_array(&num_elements, &av[1]);
	while (p[i] != NULL)
	{
		printf("num_elements=%zu, %s\n",num_elements,p[i]);
		++i;
	}
	free_wp(p);
}*/
