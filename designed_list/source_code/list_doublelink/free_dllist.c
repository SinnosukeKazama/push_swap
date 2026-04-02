/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dllist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:45:17 by skazama           #+#    #+#             */
/*   Updated: 2026/04/02 14:59:03 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/list_doublelink.h"

void	free_dllist(t_dllist *node_begin, size_t num_elements)
{
	t_dllist	*p;
	t_dllist	*p_next;

	p = node_begin;
	while (num_elements)
	{
		p_next = p->next;
		free(p);
		p = p_next;
		--num_elements;
	}
}
