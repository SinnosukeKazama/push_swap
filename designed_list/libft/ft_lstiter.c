/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:16:08 by skazama           #+#    #+#             */
/*   Updated: 2025/10/31 14:16:15 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr_l;

	ptr_l = lst;
	if (!lst || !f)
		return ;
	while (ptr_l)
	{
		f(ptr_l->content);
		ptr_l = ptr_l->next;
	}
}
