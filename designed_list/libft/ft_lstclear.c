/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:15:11 by skazama           #+#    #+#             */
/*   Updated: 2025/11/01 20:56:28 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr_l;
	t_list	*ptr_n;

	ptr_l = *lst;
	while (ptr_l)
	{
		ptr_n = ptr_l->next;
		ft_lstdelone(ptr_l, del);
		ptr_l = ptr_n;
	}
	*lst = NULL;
}
