#include "push.h"


bool	push(t_stack *dest, t_stack *src){
	t_dllist	*old_dest_head;
	t_dllist	*poped;

	if (!dest || !src)
		return (false);

	poped = pop(src);
	if (!poped)
		return (false);

	old_dest_head = dest->head;
	ft_dllstadd_front(&old_dest_head, poped);
	dest->head = poped;
	dest->num_elements++;
	return (true);
}
