/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:05 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:41:06 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/operate_stack.h"

void	rotate(t_stack *stk)
{
	if (!stk)
		return ;
	if (!stk->head)
		return ;
	if (stk->num_elements < 2)
		return ;
	if (!stk->head->next || !stk->head->prev)
		return ;
	stk->head = stk->head->next;
}
