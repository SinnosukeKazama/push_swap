#include "rotate.h"

void	rotate(t_stack *stk)
{
	stk->head = stk->head->next;
}
void	rotate_rev(t_stack *stk)
{
	stk->head = stk->head->prev;
}
