#include "libft.h"
#include <string.h>
#include <stdio.h>

char	mapi(unsigned int i, char c)
{
	if (i%2 == 0)
		return (ft_tolower(c));
	else
		return (ft_toupper(c));
}
int	main(void)
{
	char str[32];
	char *strmapi;
    strcpy(str, "LoReM iPsUm");
    strmapi = ft_strmapi(str, &mapi);
    printf("#%s#\n",strmapi);
    if (strmapi == str)
        printf("\nA new string was not returned");
    if (strmapi[11] != '\0')
        printf("\nString is not null terminated");	
}
