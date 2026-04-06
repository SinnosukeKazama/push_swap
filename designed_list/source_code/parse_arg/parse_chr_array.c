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

#include "../header/parse_arg.h"

#define ALLOCATE_FAILURE 0
#define FUNCTION_SUCCESS 1
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

static char	**append(char **ptr, char *src)
{
	const size_t	size_ptr = wplen(ptr);
	const size_t	size_new = size_ptr + 2;
	char			**ptr_new;
	size_t			i;

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
//static int	flag返す。
static char	**divide_space(char **rt, char *p)
{
	char	**rt_new;
	char	**tmp;
	size_t	i;

	/*
	is_contains_space(p))
		return (0)
	*/
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
	//return (1);
}

static char	**gen_array(char ***p_rt, char **rt_new, char **p_dup, char **p_src)
{
	int	i;

	i = -1;
	while (p_src[++i] != NULL)
	{
		/*改善
		if (divide_space(p_src))
			return (NULL);
		*/
		//
		if (is_contains_space(p_src[i]))
		{
			*p_rt = divide_space(*p_rt, p_src[i]);
			if (!*p_rt)
				return (NULL);
		}
		//
		else
		{
			*p_dup = ft_strdup(p_src[i]);
			if (!p_dup)
				return (free_wp(*p_rt), NULL);
			rt_new = append(*p_rt, *p_dup);
			if (!rt_new)
				return (free(*p_dup), free_wp(*p_rt), NULL);
			free(*p_rt);
			*p_rt = rt_new;
		}
	}
	return (*p_rt);
}

int	parse_chr_array(char ***dest, size_t *num_elements, char **p)
{
	char	**rt_new;
	char	*dup;

	rt_new = NULL;
	dup = NULL;
	*dest = malloc(sizeof(char *));
	if (!(*dest))
		return (ALLOCATE_FAILURE);
	*dest[0] = NULL;
	if (!gen_array(dest, rt_new, &dup, p))
		return (ALLOCATE_FAILURE);
	*num_elements = wplen(*dest);
	return (FUNCTION_SUCCESS);
}

//divide_spc(); DOES NOT copy char, just copy ptr.
/*CHECK MAIN
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
