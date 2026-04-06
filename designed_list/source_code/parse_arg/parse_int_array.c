/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:06:06 by skazama           #+#    #+#             */
/*   Updated: 2026/02/14 19:07:59 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parse_arg.h"
#define NO_ELEMENT 3
#define OUT_OF_RANGE 4
#define DUPLICATION_OF_ELEMENT 5
#define ALLOCATE_FAILURE 0
#define FUNCTION_SUCCESS 1
//dup
static bool	is_overlapping(int element, int *table, const size_t size_table)
{
	size_t	i;

	i = 0;
	while (i < size_table)
	{
		if (element == table[i])
			return (true);
		++i;
	}
	return (false);
}
#include <stdio.h>
int	parse_int_array(int **dest, const size_t num_elements, char **src)
{
	long int	element;
	size_t		i;

	if (num_elements == 0)
		return (NO_ELEMENT);
	i = 0;
	*dest = malloc(num_elements * sizeof(int));
	if (!(*dest))
		return (ALLOCATE_FAILURE);
	printf("af allc dest\n");
	while (i < num_elements)
	{
		if (!atol_strict(&element, src[i]))
			return (free(*dest), OUT_OF_RANGE);
		if (element < INT_MIN || element > INT_MAX)
			return (free(*dest), OUT_OF_RANGE);
		if (is_overlapping(element, *dest, i))
			return (free(*dest), DUPLICATION_OF_ELEMENT);
		(*dest)[i] = element;
		++i;
	}
	return (FUNCTION_SUCCESS);
}
