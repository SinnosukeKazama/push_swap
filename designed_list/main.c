#include "./libft/libft.h"
#include "./ft_printf/source_code/header/ft_printf.h"
#include "list_doublelink.h"

//標準入力が、整数、負の整数か？
bool	is_error_stdinput(int ac, char **av)
{
	if (ac == 1)
		return (true);
	else
		return (false);
}

void	print_dllist(t_dllist *node_begin, size_t num_node)
{
	t_dllist	*p;

	p = node_begin;
	while (num_node)
	{
		ft_printf("%s", p->content);
		p = p->next;
		--num_node;
	}
	ft_printf("\n");
}
int main(int ac, char **av)
{
	t_dllist	*node_begin;
	t_dllist	*node_new;
	char	*content_new;
	size_t	i;
	//Error
	if (is_error_stdinput(ac, av))
	{
		ft_printf("Error.\n");	
		return (1);
	}
	//str -> num
	//make LinkedList
	node_begin = NULL;
	i = 1;
	while (i < ac)
	{
		content_new = av[i];
		node_new = ft_dllstnew(content_new);
		ft_dllstadd_back(&node_begin, node_new);
		++i;
	};
	node_new->next = node_begin;//made loop
	node_begin->prev = node_new;//made loop
	for (int i = 0; i<3;++i)
	{
		rotate(&node_begin);
		ft_printf("rote %i time.\n", i);
		print_dllist(node_begin, ac - 1);
	}
	for (int i = 0; i<3;++i)
	{
		rotate_rev(&node_begin);
		ft_printf("rote_rev %i time.\n", i);
		print_dllist(node_begin, ac - 1);
	}

	//free
	free_dllist(&node_begin, ac - 1);
}
