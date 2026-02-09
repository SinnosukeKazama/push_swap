#include "../header/generaling_stack.h"

void	print_stack(t_stack *stk)
{
	if (!stk)
		return ;
	print_dllist(stk->head, stk->num_elements);
}
