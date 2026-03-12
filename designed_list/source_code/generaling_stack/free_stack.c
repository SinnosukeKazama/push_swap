#include "../header/generaling_stack.h"
void	free_stack(t_stack *stk)
{
	if (!stk)
		return ;
	free_dllist(stk->head, stk->num_elements);
	free(stk);
}

