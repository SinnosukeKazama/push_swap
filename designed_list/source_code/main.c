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
/*
#include "./header/generaling_list_doublelink.h"
#include "./header/generaling_stack.h"
#include "./header/operate_stack.h"
#include "./header/rap_operate_stack.h"
#include "./header/grewout_libft.h"
#include "./header/parse_arg.h"
#include "./header/sort.h"
*/
#include "./header/push_swap.h"

void	print_stack(t_stack *stk)
{
	t_dllist *p = stk->head;
	size_t	i;
	i=0;
	while (i < stk->num_elements)
	{
		printf("#%i\n",p->content);
	       p = p->next;
       		++i;
 	}
}	

void check_list(t_stack *s)
{
    t_dllist *cur = s->head;
    int guard = 0;

    while (cur)
    {
        if (cur->next && cur->next->prev != cur)
            printf("リンク破壊\n");
        cur = cur->next;
        if (++guard > 10000)
        {
            printf("循環してる\n");
            break;
        }
    }
}
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
		return (write(1, "Error\n", 6), 1);
	i_std_inputs = parse_int_array(num_elements, c_std_inputs);
	free_wp(c_std_inputs);
	if(!i_std_inputs)
		return (write(1, "Error\n", 6), 1);
	if(is_sorted(num_elements, i_std_inputs))
		return (free(i_std_inputs), 0);
	stk_a = gen_stack(num_elements, i_std_inputs);
	stk_b = gen_stack(0, NULL);
	free(i_std_inputs);
	if (!stk_a)
		return (1);
	assign_index(stk_a);
	if (num_elements <= 3)
		sort_under3(stk_a, stk_b);
	else
		radix_sort_stk(stk_a, stk_b);

	//print_stack(stk_a);

	free_stack(stk_a);
	free_stack(stk_b);
}
