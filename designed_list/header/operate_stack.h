#ifndef OPERATE_STACK_H
#define OPERATE_STACK_H
#include "generaling_stack.h"

void	swap(t_stack *a);
t_dllist	*pop (t_stack *src);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stk);
void	rotate_rev(t_stack *stk);

#endif//OPERATE_STACK_H
