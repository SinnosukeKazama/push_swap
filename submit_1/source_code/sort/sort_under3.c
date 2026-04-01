/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:42:43 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 14:19:48 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/sort.h"

static void	sort_3(t_stack *a, t_stack *b)
{
	t_dllist	*prev;

	prev = a->head->prev;
	while (a->head->index != 2)
	{
		prev = a->head;
		ra(a, b);
	}
	if (prev->index == 0)
	{
		sa(a, b);
		rra(a, b);
	}
	else
		ra(a, b);
}

void	sort_under3(t_stack *a, t_stack *b)
{
	if (a->num_elements == 2)
		sa(a, b);
	else if (a->num_elements == 3)
		sort_3(a, b);
}
