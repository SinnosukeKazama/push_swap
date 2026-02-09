#include "../header/rap_operate_stack.h"
void	rb(t_stack *a, t_stack *b)
{
	(void *)a;
	rotate(b);
	write(1, "rb\n", 3);
}
