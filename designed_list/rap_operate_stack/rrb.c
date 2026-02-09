
#include "../header/rap_operate_stack.h"
void	rrb(t_stack *a, t_stack *b)
{
	(void *)a;
	rotate_rev(b);
	write(1, "rrb\n", 4);
}
