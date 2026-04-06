#include "../header/parse_arg.h"

int	parse_str_array(t_list *dest, size_t *num_elements, char **src)
{
	dest = ft_lstnew(src[0]);
	if (!(dest))
		return (ALLOCATE_FAILURE);
	
	return (FUNCTION_SUCCESS);
}
int main(int ac, char **av)
{
	t_list	*dest;
	num_elements = ac - 1;
	parse_str_array(dest, &num_elements, av);
	printf("%s\n", dest->content);
}
