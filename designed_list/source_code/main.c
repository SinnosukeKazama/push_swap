/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:42:30 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 14:30:16 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

typedef struct	s_ps_info
{
	size_t	num_elements;
	t_stack	*a;
	t_stack	*b;
}	t_ps_info;
static bool	parse_inputs(t_ps_info *info, char **av)
{
	char	**str_array;
	int		*array;

	str_array = parse_chr_array(&info->num_elements, &av[1]);
	if (!str_array)
		return (write(1, "Error\n", 6), false);
	array = parse_int_array(info->num_elements, str_array);
	free_wp(str_array);
	if (!array)
		return (write(1, "Error\n", 6), false);
	if (is_sorted(info->num_elements, array))
		return (free(array), false);
	*a = gen_stack(info->num_elements, array);
	if (!(*a))
		return (free(array), false);
	*b = gen_stack(0, NULL);
	if (!(*b))
		return (free(array), false);
	return (free(array), true);
}

int	main(int ac, char **av)
{
	t_ps_info	info;

	info.num_elements = ac - 1;
	if (!parse_inputs(&info, av))
		return (1);
	assign_index(info.a);
	if (num_elements <= 3)
		sort_under3(info.a, info.b);
	else
		radix_sort_stk(info.a, info.b);
	free_stack(info.a);
	free_stack(info.b);
	return (0);
}
