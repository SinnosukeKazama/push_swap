#include "operate_stack.h"

t_dllist	*pop (t_stack *src)
{
	t_dllist *old_src_head;
	t_dllist *old_src_head_prev;
	
	if (!src || !(src->head) || !(src->num_elements))
		return (NULL);
	old_src_head = src->head;
	old_src_head_prev = src->head->prev;
	if (src->num_elements > 1){ 

		src->head = src->head->next; 
		src->head->prev = old_src_head->prev; 
		old_src_head_prev->next = src->head;
		old_src_head->next = NULL;
		old_src_head->prev = NULL;
		src->num_elements--; 
	} 
	else if(src->num_elements == 1){
		old_src_head->next = NULL;
		old_src_head->prev = NULL;
		src->head = NULL; 
		src->num_elements = 0; 
	}
	return (old_src_head);
}

