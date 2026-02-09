#include "../header/list_doublelink.h"
//warning:NULL終端していないリストに対応していない。
//今まで気づかなかった理由：loopを作る直前で呼び出していたから。直すべきか。
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
