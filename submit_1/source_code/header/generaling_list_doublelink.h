/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generaling_list_doublelink.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:58:11 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:58:15 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERALING_LIST_DOUBLELINK_H
# define GENERALING_LIST_DOUBLELINK_H
# include "grewout_libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_dllist
{
	int				content;
	size_t			num_elements;
	size_t			index;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}	t_dllist;

t_dllist	*ft_dllstnew(int content);
void		ft_dllstadd_front(t_dllist **lst, t_dllist *new);
t_dllist	*gen_dllist_loop(const size_t num_elements, int *contents);
void		free_dllist(t_dllist *node_begin, size_t num_node);

#endif// GENERALING_LIST_DOUBLELINK_H
