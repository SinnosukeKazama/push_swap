#include "libft.h"
#include <stdio.h>

void	f(unsigned int i, char *p)
{
	if (i == 0 || i % 2 != 0)
		*p = ft_tolower(*p);
	else
		*p = ft_toupper(*p);
}
int	main(void)
{
	char	s[] = "LoReM iPsUm";

	ft_striteri(s, f);
	ft_putstr_fd(s,1);
	return (0);
}
