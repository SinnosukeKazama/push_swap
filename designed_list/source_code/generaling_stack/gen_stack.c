#include "../header/generaling_stack.h"
t_stack	*gen_stack(size_t num_elements, int *contents)
{
	t_stack		*stk;

	if ((num_elements && !contents) || (!num_elements && contents))
		return (NULL);
	stk = malloc(sizeof(t_stack));
	if (!stk)
		return(NULL);
	if (!num_elements && !contents)
		stk->head = NULL;
	else
	{
		stk->head = gen_dllist_loop(num_elements, contents);
		if (!stk->head)
			return (free(stk), NULL);
	}
	stk->num_elements = num_elements;
	return (stk);
}
