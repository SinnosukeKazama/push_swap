/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_dllist_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:38:44 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:38:45 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/generaling_list_doublelink.h"

static void	ft_dllstadd_back(t_dllist **lst, t_dllist *new)
{
	t_dllist	*p;

	p = *lst;
	if (!p)
	{
		*lst = new;
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = new;
	new->prev = p;
}

t_dllist	*gen_dllist_loop(const size_t num_elements, int *contents)
{
	size_t		i;
	t_dllist	*node_begin;
	t_dllist	*node_new;

	node_begin = NULL;
	i = 0;
	while (i < num_elements)
	{
		node_new = ft_dllstnew(contents[i]);
		if (!node_new)
			return (free_dllist(node_begin, i), NULL);
		ft_dllstadd_back(&node_begin, node_new);
		++i;
	}
	node_new->next = node_begin;
	node_begin->prev = node_new;
	return (node_begin);
}
