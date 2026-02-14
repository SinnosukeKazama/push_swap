/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_ary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:58:38 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 16:11:00 by skazama          ###   ########.fr       */
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
static void	init_zero(size_t *a, const size_t num_col)
{
	size_t	i;

	i = 0;
	while (i < num_col)
	{
		a[i] = 0;
		++i;
	}
 }


static void	division_values(t_sort *s)
{
	size_t row_bucket;
	size_t	i;
	long long	la;

	i = 0;
	init_zero(s->count, RADIX);
	while (i < s->size_a)
	{
		la = (long long)(s->a[i]) - INT_MIN;
		row_bucket = (la / s->radix_cur) % RADIX;//Will be index;
		s->bucket[row_bucket * s->size_a + s->count[row_bucket]] = s->a[i];//buketに振り分け。基数ごとに分ける。
		s->count[row_bucket]++;//index_col 更新。
		++i;
	}
}
static void	collect_values(t_sort *s)
{
	size_t	i;
	size_t j;
	size_t	index_a;

	i = 0;
	index_a = 0;
	while (i < RADIX)
	{
		j = 0;
		while (j < s->count[i])
		{
			s->a[index_a++] = s->bucket[i * s->size_a + j];
			++j;
		}
		++i;
	}
}

void	radix_sort_ary(int *a, size_t size)
{
	t_sort	s;
	s.a = a;
	s.size_a = size;
	s.bucket = malloc(sizeof(int) * RADIX * s.size_a);
	s.digit_cur = 0;
	s.radix_cur = 1;
	while (s.digit_cur < DIGIT_MAX)
	{
		//分配
		division_values(&s);
		//回収
		collect_values(&s);
		s.digit_cur++;
		s.radix_cur *= RADIX;
	}
	free(s.bucket);
}
/*
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
	radix_sort_ary(a, RANGE_ARRAY);
//
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("time = %lld ns\n", diff_ns(start, end));
//
	for (size_t i = 0; i < RANGE_ARRAY; ++i){
		printf("%i ", a[i]);
	}
	puts("");
}*/
