/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:00:28 by skazama           #+#    #+#             */
/*   Updated: 2026/04/02 15:00:37 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "list_doublelink.h"

typedef struct s_stack
{
	size_t		num_elements;
	t_dllist	*head;
}	t_stack;
t_stack	*gen_stack(size_t num_elements, int *contents);
void	free_stack(t_stack *stk);

#endif//STACK_H
