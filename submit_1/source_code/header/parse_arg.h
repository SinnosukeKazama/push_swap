/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:40:04 by skazama           #+#    #+#             */
/*   Updated: 2026/04/01 11:39:30 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARG_H
# define PARSE_ARG_H
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdbool.h>
# include "grewout_libft.h"

int		*parse_int_array(const size_t num_elements, char **std_inputs);
char	**parse_chr_array(size_t *num_elements, char **p);
void	free_wp(char **p);
size_t	wplen(char **p);

#endif//PARSE_ARG_H
