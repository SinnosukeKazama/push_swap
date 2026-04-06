/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:39:30 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 10:39:32 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREWOUT_LIBFT_H
# define GREWOUT_LIBFT_H
# include <stdbool.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
#include"./libft/libft.h"


bool	atol_strict(long int *dest, const char *nptr);
void	free_dp(char **p);
int	parse_str_array(t_list **dest, size_t *num_elements, char **src);
size_t	dplen(char **p);

#endif//GREWOUT_LIBFT_H
