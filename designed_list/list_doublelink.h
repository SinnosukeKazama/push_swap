#ifndef LIST_DOUBLELINK_H
#define LIST_DOUBLELINK_H
#include "./libft/libft.h"
#include "./ft_printf/source_code/header/ft_printf.h"
typedef struct s_dllist
{
	void			*content;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}t_dllist;

//Fanction of allocate or free
t_dllist	*ft_dllstnew(void *content);
void	ft_dllstadd_back(t_dllist **lst, t_dllist *new);
void	free_dllist(t_dllist **node_begin, size_t num_node)
//Function of push swap
void	rotate(t_dllist **node_begin);
void	rotate_rev(t_dllist **node_begin);
#endif//LIST_DOUBLELINK
