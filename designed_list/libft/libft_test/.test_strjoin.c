#include <stdio.h>
#include "libft.h"

int main(void)
{
	char	*s1 = ft_strdup("ABC");
	char	*s2 = ft_strdup("abc");
	char	*s3 = NULL;

	char	*s12 = ft_strjoin(s1, s2);
	char	*s13 = ft_strjoin(s1, s3);

	printf("s12:%s\n", s12);
	printf("s13:%s\n", s13);
	free(s1);
	free(s2);
	free(s3);
	printf("SCD:free(s3)\n");
	free(s12);
	free(s13);
	printf("SCD:free(s13)\n");
}
