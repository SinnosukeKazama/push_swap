#ifndef PARSE_STDIO_H
#define PARSE_STDIO_H
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <stdbool.h>
#include "grewout_libft.h"
int	*parse_int_array(const size_t num_elements, char **std_inputs);
char	**parse_chr_array(size_t *num_elements, char **p);
void	free_wp(char **p);

#endif//PARSE_STDIO_H
