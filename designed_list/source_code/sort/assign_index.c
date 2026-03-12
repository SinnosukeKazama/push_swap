/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:23:18 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 16:48:04 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/sort.h"
static int	*copy_stk_to_ary(t_stack *stk)
{
	int *array;
	const size_t	size = stk->num_elements;
	t_dllist	*current;
	size_t	i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	current = stk->head;
	i = 0;
	while (i < size)
	{
		array[i] = current->content;
		current = current->next;
		++i;
	}
	return (array);
}

static	void	put_index(t_dllist *dest, const int *src, const size_t size)
{
	t_dllist	*current;
	size_t	i;
	size_t	j;

	current = dest;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (src[i] == current->content)
				current->index = i;
			current = current->next;
			++j;
		}
		++i;
	}
}
void	assign_index(t_stack *stk)
{
	int	*array;
	const size_t	size = stk->num_elements;

	array = copy_stk_to_ary(stk);
	if (!array)
		return ;
	radix_sort_ary(array, size);
	put_index(stk->head, array, size);
	free(array);
}
