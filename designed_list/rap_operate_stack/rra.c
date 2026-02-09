
#include "../header/rap_operate_stack.h"
void	rra(t_stack *a, t_stack *b)
{
	(void *)b;
	rotate_rev(a);
	write(1, "rra\n", 4);
}
