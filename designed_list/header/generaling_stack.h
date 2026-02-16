/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generaling_stack.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:29:27 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 15:29:39 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERALING_STACK_H
#define GENERALING_STACK_H
#include "list_doublelink.h"

typedef struct	s_stack
{
	size_t	num_elements;
	t_dllist	*head;
}	t_stack;
t_stack	*gen_stack(size_t num_elements, int *contents);
void	free_stack(t_stack *stk);
void	print_stack(t_stack *stk);

#endif//GENERALING_STACK_H
