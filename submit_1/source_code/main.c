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

static bool	parse_inputs(size_t *n_ele, t_stack **a, t_stack **b, char **av)
{
	char	**inputs_c;
	int		*inputs_i;

	inputs_c = parse_chr_array(n_ele, &av[1]);
	if (!inputs_c)
		return (write(1, "Error\n", 6), false);
	inputs_i = parse_int_array(*n_ele, inputs_c);
	free_wp(inputs_c);
	if (!inputs_i)
		return (write(1, "Error\n", 6), false);
	if (is_sorted(*n_ele, inputs_i))
		return (free(inputs_i), false);
	*a = gen_stack(*n_ele, inputs_i);
	if (!(*a))
		return (free(inputs_i), false);
	*b = gen_stack(0, NULL);
	if (!(*b))
		return (free(inputs_i), false);
	return (free(inputs_i), true);
}

int	main(int ac, char **av)
{
	size_t	num_elements;
	t_stack	*stk_a;
	t_stack	*stk_b;

	num_elements = ac - 1;
	if (!parse_inputs(&num_elements, &stk_a, &stk_b, av))
		return (1);
	assign_index(stk_a);
	if (num_elements <= 3)
		sort_under3(stk_a, stk_b);
	else
		radix_sort_stk(stk_a, stk_b);
	free_stack(stk_a);
	free_stack(stk_b);
	return (0);
}
