#include "./libft/libft.h"
#include "./ft_printf/source_code/header/ft_printf.h"
#include "list_doublelink.h"
#include "stack.h"
#include "rotate.h"
#include "push.h"

//標準入力が、整数、負の整数か？
bool	is_error_stdinput(int ac, char **av)
{
	if (ac == 1)
		return (true);
	else
		return (false);
}


int main(int ac, char **av)
{
	size_t	num_elements;
	t_stack *stk;

	//Error
	if (is_error_stdinput(ac, av))
		return (ft_printf("Error.\n"), 1);
	//allocate stack, 
	num_elements = ac - 1;
	stk = gen_stack(num_elements, &av[1]);
	if (!stk)
		return (1);
	for (size_t i = 0; i<num_elements; i++)
	{
		ft_printf("rotate %i time.\n", i);
		print_stack(stk);
		rotate(stk);
	}

	free_stack(stk);
}
