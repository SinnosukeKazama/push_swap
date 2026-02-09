
#include "../header/rap_operate_stack.h"

void	sb(t_stack *a, t_stack *b)
{
	(void *)a;
	swap(b);
	write(1, "sb\n", 3);
}
