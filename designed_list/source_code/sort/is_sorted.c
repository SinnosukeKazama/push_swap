#include "../header/sort.h"

//rt=1,0

int	is_sorted(const size_t num_elements, const int *array)
{
	size_t	i;

	i = 1;
	while (i < num_elements)
	{
		
		if (array[i - 1] > array[i])
			return (0);
		++i;
	}
	return (1);
}

/*
int main(void)
{
	int a[] = {-2,2,10,4};
	size_t sz = 4;
	printf("%i", is_sorted(a,sz));
}*/
