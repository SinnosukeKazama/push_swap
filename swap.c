
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a ^ *b;
	*a ^= tmp;
	*b ^= tmp;
}

#include <stdio.h>
int main(void)
{
	int a = 3;
	int b = 41;
	swap(&a,&b);
	printf("a=%i, b=%i\n", a, b);
}
