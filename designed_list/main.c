#include "./ft_printf/source_code/header/ft_printf.h"
#include "list_doublelink.h"
#include "generaling_stack.h"
#include "operate_stack.h"
#include "grewout_libft.h"

//標準入力が、整数、負の整数か？

bool	is_overlapping(const int element, const int *table, const size_t size_table)
{
	size_t	i;

	i = 0;
	while (i < size_table)
	{
		if (element == table[i])
			return (true);
		++i;
	}
	return (false);
}

int	*parse_int_array(const size_t num_elements, char **std_inputs)
{
	int		*elements;
	long int	element;
	size_t		i;

	if (num_elements == 0)
		return (NULL);
	i = 0;
	elements = malloc(num_elements * sizeof(int));
	if (!elements)
		return (NULL);
	while (i < num_elements)
	{
		if (!atol_strict(&element, std_inputs[i]))
			return (free(elements), NULL);
		//int範囲内か
		if (element < INT_MIN || element > INT_MAX)	
			return (free(elements), NULL);
		//重複ないか
		if (is_overlapping(element, elements, i + 1))
			return (free(elements), NULL);
		elements[i] = element;
		++i;
	}
	return (elements);
}
	
int main(int ac, char **av)
{
	const size_t	num_elements = ac - 1;
	int	*std_inputs;
	t_stack *stk_a;
	t_stack *stk_b;

	std_inputs = parse_int_array(num_elements, &av[1]);
	if(!std_inputs)
		return (ft_printf("Error\n"), 1);
	

	//allocate stack, 
	stk_a = gen_stack(num_elements, std_inputs);
	stk_b = gen_stack(0, NULL);
	free(std_inputs);
	if (!stk_a)
		return (1);
//	t_dllist *p = pop(stk_a);

//		ft_printf("p->content:%i, p:%p, p->next:%p, p->prev;%p\n", p->content,p, p->next, p->prev);
	ft_printf("a:stk->content:%i, stk->head:%p, stk->head->next:%p, stk->head->prev:%p\n",stk_a->head->content,stk_a->head,stk_a->head->next, stk_a->head->prev);
//	ft_printf("b:stk->content:%i, stk->head:%p, stk->head->next:%p, stk->head->prev:%p\n",stk_b->head->content,stk_b->head,stk_b->head->next, stk_b->head->prev);
	
	push(stk_b, stk_a);
	ft_printf("a:");
	print_stack(stk_a);
	ft_printf("b:");
	print_stack(stk_b);

	swap(stk_a);
	ft_printf("a:");
	print_stack(stk_a);
	ft_printf("b:");
	print_stack(stk_b);
/*
	swap(stk_a);
	ft_printf("a:");
	print_stack(stk_a);
	ft_printf("b:");
	print_stack(stk_b);
	*/


	free_stack(stk_a);
	free_stack(stk_b);
}
