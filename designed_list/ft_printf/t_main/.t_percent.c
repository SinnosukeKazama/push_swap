#include <stdio.h>
#include "../source_code/header/ft_printf.h"

int main(void)
{
	int ft, st;

	ft = ft_printf("%%");//%, 1
	printf("\n");
	st = printf("%%");//%, 1
	printf("\n");
	printf("rt: ft=%i, st=%i\n", ft, st);//out->ok, rt ft=st ->ok

	printf("\n\n");
	ft = ft_printf("%%%%");//%%, 2
	printf("\n");
	st = printf("%%%%");//%%, 2
	printf("\n");
	printf("rt: ft=%i, st=%i\n", ft, st);//out->ok, rt ft=st ->ok

	printf("\n\n");
	ft = ft_printf("%%%");//%, -1
	printf("\n");
	st = printf("%%%");//%, -1
	printf("\n");
	printf("rt: ft=%i, st=%i\n", ft, st);//out->ok, rt ft=st ->ok
	
	printf("\n\n");
	ft = ft_printf("%%%%%");//%%, -1
	printf("\n");
	st = printf("%%%%%");//%%, -1
	printf("\n");
	printf("rt: ft=%i, st=%i\n", ft, st);//out ft=st ->ok, rt ft=st ->ok
	
	printf("\n\n");
	ft = ft_printf("%%", 2);//%, 1//第２引数読み込まれず。->ok
	printf("\n");
	st = printf("%%", 2);//%, 1//第２引数読み込まれず。->ok
	printf("\n");
	printf("rt: ft=%i, st=%i\n", ft, st);//out ft=st, rt ft=st ->ok

	printf("\n\n");
	ft = ft_printf("%%%", 2);//%, 1//第２引数読み込まれず。->ok
	printf("\n");
	st = printf("%%%", 2);//%, 1//第２引数読み込まれず。->ok
	printf("\n");
	printf("rt: ft=%i, st=%i\n", ft, st);//out ft=st, rt ft=st ->ok
}
