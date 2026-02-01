#include "./libft/libft.h"
#include "./ft_printf/source_code/header/ft_printf.h"

int main(int ac, char **av)
{
	t_list	*node_begin;
	t_list	*node_new;
	char	*content_new;
	size_t	i;
	//Error
	
	//str -> num
	//make LinkedList
	node_begin = NULL;
	i = 1;
	while (i < ac)
	{
		content_new = av[i];
		node_new = ft_lstnew(content_new);
		ft_lstadd_back(&node_begin, node_new);
		ft_printf("ptr_begin=%p, ptr_new=%p, content=%s\n", node_begin, node_new, content_new);
		++i;
	};
}
