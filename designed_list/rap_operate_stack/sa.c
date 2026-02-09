
#include "../header/rap_operate_stack.h"

void	sa(t_stack *a, t_stack *b)
{
	(void *)b;
	swap(a);
	write(1, "sa\n", 3);
}
