/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:37:59 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:38:02 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/generaling_list_doublelink.h"

void	ft_dllstadd_front(t_dllist **lst, t_dllist *new)
{
	t_dllist	*p;
	t_dllist	*old_p_prev;

	p = *lst;
	if (!p)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
		return ;
	}
	old_p_prev = p->prev;
	new->next = p;
	p->prev = new;
	new->prev = old_p_prev;
	old_p_prev->next = new;
}
