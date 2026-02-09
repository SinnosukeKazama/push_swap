#include "../header/list_doublelink.h"
void	free_dllist(t_dllist *node_begin, size_t num_elements)
{
	t_dllist	*p;
	t_dllist	*p_next;

	p = node_begin;
	while (num_elements)
	{
		p_next = p->next;
		free(p);
		p = p_next;
		--num_elements;
	}
}
