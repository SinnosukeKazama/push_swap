
#include "../header/rap_operate_stack.h"
void	rrr(t_stack *a, t_stack *b)
{
	rotate_rev(a);
	rotate_rev(b);
	write(1, "rrr\n", 4);
}
