#include "tmp.h"
#define ALLOCATE_FAILURE 2
#define FUNCTION_SUCCESS 1
#include<stdio.h>

//for dbg
void	put_str_array(char **p)
{
	size_t i = 0;
	while (p[i])
	{
		printf("%p, p[%zu]=(%s)\n",p[i],i,p[i]);
		i++;
	}
}
void	del(void *content)
{
	free(content);
}
int	dup_str_array(char **dest, char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
			return (ALLOCATE_FAILURE);
		++i;
	}
	put_str_array(dest);//dbg
	return (FUNCTION_SUCCESS);
}
int divide_space(t_list , char **src)
{
	tmp = ft_split(src, ' ');
	if (!tmp)
		return (ALLOCATE_FAILURE);
}
int	parse_str_array(t_list **dest, size_t *num_elements, char **src)
{
	size_t	i;
	char	**str_array;//
	t_list	*new;

	//文字列配列の作成
	//split
	put_str_array(dest);//dbg
	//複製
	if (dup_str_array(str_array, src) != FUNCTION_SUCCESS)
		return (free_dp(str_array), ALLOCATE_FAILURE);
	
	//listに挿入
	// i = 0;
	// *dest = ft_lstnew(str_array[i++]);
	// if (!(*dest))
	// 	return (free_dp(str_array), ALLOCATE_FAILURE);
	
	// while (str_array[i])
	// {
	// 	new = ft_lstnew(str_array[i]);
	// 	if (!new)
	// 		return  (ft_lstclear(dest, del), free_dp(str_array),ALLOCATE_FAILURE);
	// 	ft_lstadd_back(dest, new);
	// 	++i;
	// }
	return (FUNCTION_SUCCESS);
}
int main(int ac, char **av)
{
	t_list	*node = NULL;
	t_list	*head = NULL;
	size_t num_elements = ac - 1;
	if (parse_str_array(&node, &num_elements, &av[1]) != FUNCTION_SUCCESS)
		return (1);
/*
	head = node;
	while (node)
	{
		printf("%s\n", (char*)node->content);
		node = node->next;
	}

	ft_lstclear(&head, del);
	*/
}
