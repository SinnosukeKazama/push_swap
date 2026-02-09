#include "../header/operate_stack.h"

void	swap(t_stack *stk)
{
	t_dllist	*stk_head_next;
	int	tmp;


	if (!stk)
		return ;
	if (!stk->head)
		return ;
	if (stk->num_elements < 2)	
		return ;
	stk_head_next = stk->head->next;
	tmp = stk_head_next->content;
	stk_head_next->content = stk->head->content;
	stk->head->content = tmp;
}
