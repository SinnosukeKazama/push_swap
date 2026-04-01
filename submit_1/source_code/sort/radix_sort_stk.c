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

static size_t	max_bitdigit(t_stack *stk)
{
	const size_t	max_indexdigit = stk->num_elements - 1;
	size_t			num_bits;

	num_bits = 0;
	while (max_indexdigit >> num_bits)
		++num_bits;
	return (num_bits);
}

static void	pass_bit(t_stack *a, t_stack *b, size_t bit)
{
	const size_t	size = a->num_elements;
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (((a->head->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a, b);
		++i;
	}
	while (b->num_elements > 0)
		pa(a, b);
}

void	radix_sort_stk(t_stack *a, t_stack *b)
{
	const size_t	max_bits = max_bitdigit(a);
	size_t			shift;

	shift = 0;
	while (shift < max_bits)
	{
		pass_bit(a, b, shift);
		shift++;
	}
}
