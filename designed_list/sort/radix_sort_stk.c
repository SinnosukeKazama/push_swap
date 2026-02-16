/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_stk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:50:38 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 18:34:21 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/sort.h"

static	size_t	max_bitdigit(t_stack *stk)
{
	const size_t	max_indexdigit = stk->num_elements - 1;//(dec)
	size_t		num_bits;

	num_bits = 0;
	while (max_indexdigit>>num_bits)
		++num_bits;
	return (num_bits);
}
void	radix_sort_stk(t_stack *a, t_stack *b)
{
	const size_t	size = a->num_elements;
	const size_t	max_bits = max_bitdigit(a);//(bit)
	size_t	bit_cur;
	size_t	i;

	bit_cur = 0;
	while (bit_cur < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->head->index>>bit_cur) & 1) == 0)
				pb(a,b);
			else
				ra(a,b);
			++i;
		}
		while (b->num_elements > 0)//return all elements b to a
			pa(a,b);
		++bit_cur;
	}
}
