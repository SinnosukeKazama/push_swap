#include "../header/operate_stack.h"

void	rotate(t_stack *stk)
{
	if (!stk)
		return ;
	if (!stk->head)
		return ;
	if (stk->num_elements < 2)
		return ;
	if (!stk->head->next || !stk->head->prev)
		return ;
	stk->head = stk->head->next;
}
