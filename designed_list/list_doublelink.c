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

t_dllist	*gen_dllist_loop(const size_t num_elements, char **contents)
{
	size_t	i;
	t_dllist	*node_begin;
	t_dllist	*node_new;

	node_begin = NULL;
	i = 0;
	while (i < num_elements)
	{//must error check
		node_new = ft_dllstnew(contents[i]);
		if (!node_new)
			if (free_dllist(node_begin, i), NULL);
		ft_dllstadd_back(&node_begin, node_new);
		++i;
	}
	node_new->next = node_begin;//made loop
	node_begin->prev = node_new;//made loop
	return (node_begin);
}

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

void	print_dllist(t_dllist *node_begin, size_t num_elements)
{
	t_dllist	*p;

	p = node_begin;
	while (num_elements)
	{
		ft_printf("%s", p->content);
		p = p->next;
		--num_elements;
	}
	ft_printf("\n");
}

