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
