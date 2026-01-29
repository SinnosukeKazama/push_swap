/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:16:33 by skazama           #+#    #+#             */
/*   Updated: 2025/11/01 21:05:06 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_l;

	ptr_l = lst;
	if (ptr_l == NULL)
		return (NULL);
	while (ptr_l->next)
		ptr_l = ptr_l->next;
	return (ptr_l);
}
