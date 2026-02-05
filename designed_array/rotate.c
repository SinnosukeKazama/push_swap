#include "rot.h"

void	rotate(t_array *rotated)
{
	size_t	i = 0;
	int	tmp;

	tmp = rotated->ptr[i];
	while (++i < rotated->num_elements)
	{
		rotated->ptr[i - 1] = rotated->ptr[i];
		if (i == rotated->num_elements - 1)
			rotated->ptr[i] = tmp;
	}
}
/*
int main(void)
{
	int ptr[] = {100,3,4,6,8};
	t_array	a;

	a.ptr = ptr;
	a.num_elements = 5;
	rotate(&a);
	for (int i = 0; i < a.num_elements; ++i)
		printf("%i\n", ptr[i]);
}*/
