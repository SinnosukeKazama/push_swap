
#include "../header/rap_operate_stack.h"

void	ra(t_stack *a, t_stack *b)
{
	(void *)b;
	rotate(a);
	write(1, "ra\n", 3);
}
