#ifndef GREWOUT_LIBFT_H
#define GREWOUT_LIBFT_H
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

bool	atol_strict(long int *dest, const char *nptr);
int	ft_isdigit(int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif//GREWOUT_LIBFT_H
