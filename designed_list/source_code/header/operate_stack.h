/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:14:01 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 16:14:17 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_STACK_H
#define OPERATE_STACK_H
#include "generaling_stack.h"

void	swap(t_stack *a);
t_dllist	*pop (t_stack *src);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stk);
void	rotate_rev(t_stack *stk);

#endif//OPERATE_STACK_H
