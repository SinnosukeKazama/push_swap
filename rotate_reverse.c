#include "rot.h"

void	rotate_reverse(t_array *rrotated)
{
	size_t	i = 0;
	int	tmp;

	i = rrotated->num_elements-1;
	tmp = rrotated->ptr[i];
	while (1)
	{
		--i;
		rrotated->ptr[i + 1] = rrotated->ptr[i];
		if (i == 0)
		{
			rrotated->ptr[i] = tmp;
			break;
		}
	}
}

int main(void)
{
	int ptr[] = {100,3,4,6,8};
	t_array	a;

	a.ptr = ptr;
	a.num_elements = 5;
	rotate_reverse(&a);
	for (int i = 0; i < a.num_elements; ++i)
		printf("%i\n", ptr[i]);
}
