#ifndef STACK_H
#define STACK_H

#include "list_doublelink.h"

typedef struct	s_stack
{
	t_dllist	*head;
	size_t		num_elements;
}	t_stack;

t_stack	*gen_stack(size_t num_element, char **contents);
void	free_stack(t_stack *stk);
void	print_stack(t_stack *stk);
#endif//STACK_H
