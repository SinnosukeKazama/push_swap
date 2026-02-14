#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define RADIX 256
#define RANGE_ARRAY 256
#define DIGIT_MAX 4
//
#include <time.h>

long long diff_ns(struct timespec a, struct timespec b)
{
    return (b.tv_sec - a.tv_sec) * 1000000000LL + (b.tv_nsec - a.tv_nsec);
}
//
void	init_zero(size_t *a, const size_t num_col)
{
	size_t	i;

	i = 0;
	while (i < num_col)
	{
		a[i] = 0;
		++i;
	}
}

int min_value(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
int negamin_array(int *a, const size_t num_col)
{
	int	min;
	size_t	i;

	i = 0;
	min = 0;
	while (i < num_col)
	{
		min = min_value(a[i], min);
		++i;
	}
	return (min);
} 


void	division_values(const int *a, int bucket[RADIX][RANGE_ARRAY], size_t count[RADIX], const size_t logr)
{
	size_t row_bucket;
	size_t	i;
	long long	la;

	i = 0;
	init_zero(count, RADIX);
	while (i < RANGE_ARRAY)
	{
		la = (long long)a[i] - INT_MIN;
		row_bucket = (la >> logr) & 255;//Will be index;
//printf("#row_bucket=%zu\n", row_bucket);
		bucket[row_bucket][count[row_bucket]] = a[i];//buketに振り分け。基数ごとに分ける。
		++count[row_bucket];//index_col 更新。
		++i;
	}
}
void	collect_values(int *a, const int bucket[RADIX][RANGE_ARRAY], const size_t count[RADIX])
{
	size_t	i;
	size_t j;
	size_t	index_a;

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
}

void	radix_sort(int *a)
{
	int bucket[RADIX][RANGE_ARRAY];
	size_t count[RADIX];
	int digit;
	int logr;

	digit = 0;
	logr = 1;
	while (digit < DIGIT_MAX)
	{
		//分配
		division_values(a, bucket, count, logr);
		//回収
		collect_values(a, bucket, count);
		++digit;
		logr += 8;
	}
}
int main(void)
{
	int a[RANGE_ARRAY];

	for (size_t i = 0; i < RANGE_ARRAY; ++i){
		a[i] = rand() % INT_MAX + 1;
		if (i % 10 == 0)
			a[i] = -a[i];
		printf("%i ", a[i]);
	}
	puts("");
//
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
//
	radix_sort(a);
//
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("time = %lld ns\n", diff_ns(start, end));
//
	int old = a[0];
	for (size_t i = 0; i < RANGE_ARRAY; ++i){
		if (old > a[i])
			printf("Error.\n");
		else
			printf("%i ", a[i]);
		old = a[i];
	}
	puts("");
}
