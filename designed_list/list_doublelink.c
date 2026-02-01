#include "list_doublelink.h"

t_dllist	*ft_dllstnew(void *content)
{
	t_dllist	*node_new;

	node_new = (t_dllist *)ft_calloc(1, sizeof(t_dllist));
	if (!node_new)
		return (NULL);
	node_new->content = content;
	node_new->next = NULL;
	node_new->prev = NULL;
	return (node_new);
}

void	ft_dllstadd_back(t_dllist **lst, t_dllist *new)
{
	t_dllist	*p;

	p = *lst;
	if (!p)
	{
		*lst = new;
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = new;
	new->prev = p;
}
