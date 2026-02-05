#include "stack.h"


t_stack	*gen_stack(size_t num_elements, char **contents)
{
	t_stack		*stk;

	stk = malloc(sizeof(t_stack));
	if (!stk)
		return(NULL);
	stk->head = gen_dllist_loop(num_elements, contents);
	if (!stk->head)
		return (free(stk), NULL);
	stk->num_elements = num_elements;
	return (stk);
}

void	free_stack(t_stack *stk)
{
	if (!stk)
		return ;
	free_dllist(stk->head, stk->num_elements);
	free(stk);
}

void	print_stack(t_stack *stk)
{
	if (!stk)
		return ;
	print_dllist(stk->head, stk->num_elements);
}
