#include "./ft_printf/source_code/header/ft_printf.h"
#include "./header/list_doublelink.h"
#include "./header/generaling_stack.h"
#include "./header/operate_stack.h"
#include "./header/grewout_libft.h"
#include "./header/parse_stdio.h"
//標準入力が、整数、負の整数か？


	
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
