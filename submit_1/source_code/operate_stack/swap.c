/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:25 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:41:26 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/operate_stack.h"

void	swap(t_stack *stk)
{
	t_dllist	*stk_head_next;
	int			tmp;

	if (!stk)
		return ;
	if (!stk->head)
		return ;
	if (stk->num_elements < 2)
		return ;
	stk_head_next = stk->head->next;
	tmp = stk_head_next->content;
	stk_head_next->content = stk->head->content;
	stk->head->content = tmp;
}
