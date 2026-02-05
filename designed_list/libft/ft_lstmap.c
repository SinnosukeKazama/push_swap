/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:17:15 by skazama           #+#    #+#             */
/*   Updated: 2025/11/09 10:59:10 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode_front;
	t_list	*newnode;
	void	*newcont;

	if (!lst || !f || !del)
		return (NULL);
	newnode_front = NULL;
	while (lst)
	{
		newcont = f(lst->content);
		newnode = ft_lstnew(newcont);
		if (!newnode)
		{
			del(newcont);
			ft_lstclear(&newnode_front, del);
			return (NULL);
		}
		ft_lstadd_back(&newnode_front, newnode);
		lst = lst->next;
	}
	return (newnode_front);
}
