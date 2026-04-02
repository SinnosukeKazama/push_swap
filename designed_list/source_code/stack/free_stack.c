/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:37:21 by skazama           #+#    #+#             */
/*   Updated: 2026/04/02 15:01:03 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/stack.h"

void	free_stack(t_stack *stk)
{
	if (!stk)
		return ;
	free_dllist(stk->head, stk->num_elements);
	free(stk);
}
