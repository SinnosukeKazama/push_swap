#include "../header/list_doublelink.h"
void	print_dllist(t_dllist *node_begin, size_t num_elements)
{
	t_dllist	*p;

	p = node_begin;
	while (num_elements)
	{
		ft_printf("%i", p->content);
		p = p->next;
		--num_elements;
	}
	ft_printf("\n");
}
