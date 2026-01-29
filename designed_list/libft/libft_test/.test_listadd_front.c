#include "libft.h"
#include <stdio.h>
int main(void)
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = ft_strdup("lorem");
	char		*str2 = ft_strdup("ipsum");
	char		*str3 = ft_strdup("dolor");
	char		*str4 = ft_strdup("sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	if (!elem || !elem2 || !elem3 || !elem4)
		return (0);
	else
	{
		begin = NULL;
		ft_lstadd_front(&begin, elem4);
		ft_lstadd_front(&begin, elem3);
		ft_lstadd_front(&begin, elem2);
		ft_lstadd_front(&begin, elem);
		printf("elem4: %p, ->next:%p\n",elem4, elem4->next); 	
		printf("elem3: %p, ->next:%p\n",elem3, elem3->next); 	
		printf("elem2: %p, ->next:%p\n",elem2, elem2->next); 	
		printf("elem : %p, ->next:%p\n",elem , elem->next); 
		printf("list size: %d\n", ft_lstlast(elem));	
		while (begin)
		{
			printf("%s" ,(char *)begin->content);
			begin = begin->next;
		}
	}
	return (0);
}
