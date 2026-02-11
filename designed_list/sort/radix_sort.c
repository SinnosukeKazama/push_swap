#include <stdio.h>
#include <stdlib.h>
#define RADIX 10
#define RANGE_ARRAY 256

void	init_zero(int *a, const size_t num_col)
{
	size_t	i;

	i = 0;
	while (i < num_col)
	{
		a[i] = 0;
		++i;
	}
}
void	init_zero_2d(int **a, const size_t num_raw, const size_t num_col)
{
	size_t i;

	i = 0;
	while (i < num_raw)
	{
		init_zero(a[i], num_col);
		++i;
	}
}
void	radix_sort(int *a)
{
	int bucket[RADIX][RANGE_ARRAY];
	int count[RADIX];
	int digit;
	int radix;
	size_t i;
	size_t j;
	size_t index_a;

	digit = 0;
	radix = 1;
	while (digit < 3)
	{
		//分配
		i = 0;
		init_zero(count, RANGE_ARRAY);
		while (i < RANGE_ARRAY)
		{
			int key = (a[i] / radix) % RADIX;//Will be index;
			bucket[key][count[key]] = a[i];//buketに振り分け。基数ごとに分ける。
			++count[key];//index_col 更新。
			++i;
		}
		//回収
		i = 0;
		index_a = 0;
		while (i < RADIX)
		{
			j = 0;
			while (j < count[i])
			{
				a[index_a++] = bucket[i][j];
				++j;
			}
			++i;
		}
		++digit;
		radix *= 10;
	}
}
int main(void)
{
	int a[RANGE_ARRAY];

	for (size_t i = 0; i < RANGE_ARRAY; ++i){
		a[i] = rand() % 999 + 1;
		printf("%i ", a[i]);
	}
	puts("");
	radix_sort(a);
	for (size_t i = 0; i < RANGE_ARRAY; ++i){
		printf("%i ", a[i]);
	}
	puts("");
}
