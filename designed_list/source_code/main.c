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
#define MAIN_SUCCESS 0
#define MAIN_FAILURE 1
#define ALLOCATE_FAILURE 0
#define FUNCTION_SUCCESS 1
#define ALREADY_SORTED 2

typedef struct	s_ps_info
{
	size_t	num_elements;
	t_stack	*a;
	t_stack	*b;
	char	**str_array;
	int		*array;
}	t_ps_info;


static int	parse_inputs(t_ps_info *info, char **av)
{
	if (parse_chr_array(&info->str_array, &info->num_elements, &av[1]) != FUNCTION_SUCCESS)
		return (write(1, "Error\n", 6), ALLOCATE_FAILURE);
	printf("af par_chr\n");
	if (parse_int_array(&info->array, info->num_elements, info->str_array) != FUNCTION_SUCCESS)
		return (write(1, "Error\n", 6), ALLOCATE_FAILURE);
	printf("af par_int\n");
	free_wp(info->str_array);
	printf("af free str_array\n");
	if (is_sorted(info->num_elements, info->array))
		return (free(info->array), ALREADY_SORTED);
	return (FUNCTION_SUCCESS);
}

static int	gen_both_stack(t_ps_info *info)
{
	info->a = gen_stack(info->num_elements, info->array);
	if (!info->a)
		return (free(info->array), ALLOCATE_FAILURE);
	info->b = gen_stack(0, NULL);
	if (!info->b)
		return (free(info->array),free_stack(info->a), ALLOCATE_FAILURE);
	free(info->array);
	return (FUNCTION_SUCCESS);
}

static void	run_sort(t_ps_info *info)
{
	assign_index(info->a);
	if (info->num_elements <= 3)
		sort_under3(info->a, info->b);
	else
		radix_sort_stk(info->a, info->b);
}

static void	free_both_stack(t_ps_info *info)
{
	free_stack(info->a);
	free_stack(info->b);
}

int	main(int ac, char **av)
{
	t_ps_info	info;

	info.num_elements = ac - 1;
	printf("bf par_in\n");
	if (parse_inputs(&info, av) != FUNCTION_SUCCESS)
		return (MAIN_FAILURE);
	printf("af par_in\n");
	if (gen_both_stack(&info) != FUNCTION_SUCCESS)
		return (MAIN_FAILURE);
	run_sort(&info);
	free_both_stack(&info);
	return (MAIN_SUCCESS);
}
