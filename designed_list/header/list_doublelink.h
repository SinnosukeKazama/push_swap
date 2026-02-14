#ifndef LIST_DOUBLELINK_H
#define LIST_DOUBLELINK_H
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include "../ft_printf/source_code/header/ft_printf.h"
#include "grewout_libft.h"
typedef struct s_dllist
{
	int		content;
	size_t		num_elements;
	size_t		index;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}t_dllist;

//Fanction of allocate or free
t_dllist	*ft_dllstnew(int content);
void	ft_dllstadd_back(t_dllist **lst, t_dllist *new);
void	ft_dllstadd_front(t_dllist **lst, t_dllist *new);
t_dllist	*gen_dllist_loop(const size_t num_elements, int *contents);
void	free_dllist(t_dllist *node_begin, size_t num_node);

void	print_dllist(t_dllist *node_begin, size_t num_node);
#endif//LIST_DOUBLELINK
