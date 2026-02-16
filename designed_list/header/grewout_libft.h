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
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif//GREWOUT_LIBFT_H
