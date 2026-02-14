/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:09:03 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 14:09:53 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/sort.h"
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


void	division_values(const int *a, int bucket[RADIX][RANGE_ARRAY], size_t count[RADIX], const size_t radix)
{
	size_t row_bucket;
	size_t	i;
	long long	la;

	i = 0;
	init_zero(count, RADIX);
	while (i < RANGE_ARRAY)
	{
		la = (long long)a[i] - INT_MIN;
		row_bucket = (la / radix) % RADIX;//Will be index;
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
	int radix;

	digit = 0;
	radix = 1;
	while (digit < DIGIT_MAX)
	{
		//分配
		division_values(a, bucket, count, radix);
		//回収
		collect_values(a, bucket, count);
		++digit;
		radix *= 10;
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
	for (size_t i = 0; i < RANGE_ARRAY; ++i){
		printf("%i ", a[i]);
	}
	puts("");
}
