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

#include "../header/parse_stdio.h"

static bool	is_overlapping(const int element, const int *table, const size_t size_table)
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

int	*parse_int_array(const size_t num_elements, char **std_inputs)
{
	int		*elements;
	long int	element;
	size_t		i;

	if (num_elements == 0)
		return (NULL);
	i = 0;
	elements = malloc(num_elements * sizeof(int));
	if (!elements)
		return (NULL);
	while (i < num_elements)
	{
		if (!atol_strict(&element, std_inputs[i]))
			return (free(elements), NULL);
		//int範囲内か
		if (element < INT_MIN || element > INT_MAX)	
			return (free(elements), NULL);
		//重複ないか
		if (is_overlapping(element, elements, i + 1))
			return (free(elements), NULL);
		elements[i] = element;
		++i;
	}
	return (elements);
}
