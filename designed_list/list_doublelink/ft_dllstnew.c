#include "../header/list_doublelink.h"

t_dllist	*ft_dllstnew(int content)
{
	t_dllist	*node_new;

	node_new = (t_dllist *)ft_calloc(1, sizeof(t_dllist));
	if (!node_new)
		return (NULL);
	node_new->content = content;
	node_new->index = 0;
	node_new->next = NULL;
	node_new->prev = NULL;
	return (node_new);
}
