#include "../header/list_doublelink.h"

void ft_dllstadd_front(t_dllist **lst, t_dllist *new) 
{
	t_dllist *p;
	t_dllist *old_p_prev;
	p = *lst;
	if (!p) 
	{ 
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
		return ;
	} 
	old_p_prev = p->prev;
	new->next = p;
	p->prev = new;
	new->prev = old_p_prev;
	old_p_prev->next = new;
}
