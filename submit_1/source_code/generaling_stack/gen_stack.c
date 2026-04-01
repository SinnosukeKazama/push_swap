/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:37:36 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:37:39 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/generaling_stack.h"

t_stack	*gen_stack(size_t num_elements, int *contents)
{
	t_stack		*stk;

	if ((num_elements && !contents) || (!num_elements && contents))
		return (NULL);
	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	if (!num_elements && !contents)
		stk->head = NULL;
	else
	{
		stk->head = gen_dllist_loop(num_elements, contents);
		if (!stk->head)
			return (free(stk), NULL);
	}
	stk->num_elements = num_elements;
	return (stk);
}
