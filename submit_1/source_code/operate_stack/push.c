/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:40:51 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:40:53 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/operate_stack.h"

void	push(t_stack *dest, t_stack *src)
{
	t_dllist	*old_dest_head;
	t_dllist	*poped;

	if (!src)
		return ;
	poped = pop(src);
	if (!poped)
		return ;
	old_dest_head = dest->head;
	ft_dllstadd_front(&old_dest_head, poped);
	dest->head = poped;
	dest->num_elements++;
}
