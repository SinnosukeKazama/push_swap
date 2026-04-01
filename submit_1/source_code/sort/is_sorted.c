/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:42:02 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 14:10:39 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/sort.h"

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

/*CHECK MAIN
int main(void)
{
	int a[] = {-2,2,10,4};
	size_t sz = 4;
	printf("%i", is_sorted(a,sz));
}*/
