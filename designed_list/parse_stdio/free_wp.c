#include "../header/parse_stdio.h"

void	free_wp(char **p)
{
	size_t	i;

	if (!p)
		return ;
	i = 0;
	while (p[i] != NULL)
	{
		free(p[i]);
		++i;
	}
	free(p);
}
