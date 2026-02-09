#include "../header/operate_stack.h"


void	push(t_stack *dest, t_stack *src){
	t_dllist	*old_dest_head;
	t_dllist	*poped;

	if (!src)
		return ;

	poped = pop(src);
	if (!poped)
		return ;
	old_dest_head = dest->head;
	ft_dllstadd_front(&old_dest_head, poped);
	dest->head = poped;
	dest->num_elements++;
}
