/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:05:43 by skazama           #+#    #+#             */
/*   Updated: 2026/04/02 15:09:02 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# define RADIX 10
# define DIGIT_MAX 10
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "wrap_operate_stack.h"

typedef struct s_sort
{
	int		*a;
	int		*bucket;
	size_t	count[RADIX];
	size_t	size_a;
	size_t	digit_cur;
	size_t	radix_cur;
}	t_sort;
void	sort_stack(t_stack *a, t_stack *b);
void	radix_sort_ary(int *a, size_t size);
void	radix_sort_stk(t_stack *a, t_stack *b);
void	assign_index(t_stack *stk);
int		is_sorted(const size_t num_elements, const int *array);
void	sort_under3(t_stack *a, t_stack *b);

#endif//SORT_H
