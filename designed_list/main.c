/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:42:30 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 19:14:44 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/source_code/header/ft_printf.h"
#include "./header/list_doublelink.h"
#include "./header/generaling_stack.h"
#include "./header/operate_stack.h"
#include "./header/rap_operate_stack.h"
#include "./header/grewout_libft.h"
#include "./header/parse_stdio.h"
#include "./header/sort.h"


int main(int ac, char **av)
{
	size_t	num_elements;
	char	**c_std_inputs;
	int	*i_std_inputs;
	t_stack *stk_a;
	t_stack *stk_b;

	num_elements = ac - 1;
	c_std_inputs = parse_chr_array(&num_elements,&av[1]);//init num_elemen
	if (!c_std_inputs)
		return (1);
	i_std_inputs = parse_int_array(num_elements, c_std_inputs);
	if (!i_std_inputs)
		return (1);
	free_wp(c_std_inputs);
	if(!i_std_inputs)
		return (ft_printf("Error\n"), 1);
	stk_a = gen_stack(num_elements, i_std_inputs);
	stk_b = gen_stack(0, NULL);
	free(i_std_inputs);
	if (!stk_a)
		return (1);
	assign_index(stk_a);
	radix_sort_stk(stk_a, stk_b);

	//print_stack(stk_a);

	free_stack(stk_a);
	free_stack(stk_b);
}
