#include "../source_code/header/ft_printf.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

void	t_null(void)
{
	printf("t_null---------------------------\n");
	int re_ft = ft_printf(NULL);
	int re_io = printf(NULL);
	printf("\nre_ ft=%i, io=%i\n", re_ft, re_io);
}
void	t_char(void)
{
	int re_ft, re_io;
	printf("t_char-------------------\n");
	printf("1)\n");
	re_ft = ft_printf("%c", 'D'); // ok
	re_io = printf("%c", 'D');
	printf("\nre_ ft=%i, io=%i\n", re_ft, re_io); // re ok
	printf("2)\n");
	re_ft = ft_printf("%c%c", 'D', 'D'); // ok
	re_io = printf("%c%c", 'D', 'D');
	printf("\nre_ ft=%i, io=%i\n", re_ft, re_io); // re ok
	printf("\n");
}
void	t_str(void)
{
	int		re_io;
	char	*s;
	char	*s2;

	printf("t_str-------------------------\n");
	printf("1)\n");
	int re_ft = ft_printf("%s", "ABC"); // ok
	printf("\n");
	re_io = printf("%s", "ABC");
	printf("\n");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("2)\n");
	s = "ABCDE";
	re_ft = ft_printf("%s", s); // ok
	printf("\n");
	re_io = printf("%s", s);
	printf("\n");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("3)\n");
	s2 = "123456";
	re_ft = ft_printf("%s%s", s, s2); // ok
	printf("\n");
	re_io = printf("%s%s", s, s2);
	printf("\n");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("4)\n");
	re_ft = ft_printf("this is test3)%s%s", s, s2); // ok
	printf("\n");
	re_io = printf("this is test3)%s%s", s, s2);
	printf("\n");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("5)\n");
	re_ft = ft_printf("NULL %s NULL", NULL);
	re_io = printf("NULL %s NULL", NULL);
	printf("\n");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
}

void	t_str_and_char(void)
{
	int	re_ft;
	int	re_io;

	printf("t_str_and_char--------------------------\n");
	re_ft = ft_printf("%s%c\n", "ABC", 'd');
	re_io = printf("%s%c\n", "ABC", 'd');
	printf("\n");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
}

void	t_int(void)
{
	int	re_ft;
	int	re_io;

	printf("t_int----------------------\n");
	printf("1)\n");
	re_ft = ft_printf("%d\n", 10);
	re_io = printf("%d\n", 10);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("2)\n");
	re_ft = ft_printf("%d\n", INT_MIN);
	re_io = printf("%d\n", INT_MIN);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("3)\n");
	re_ft = ft_printf("%d\n", INT_MAX);
	re_io = printf("%d\n", INT_MAX);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("4)\n");
	re_ft = ft_printf("%d\n", 0);
	re_io = printf("%d\n", 0);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("5)\n");
	re_ft = ft_printf("%d\n", -0);
	re_io = printf("%d\n", -0);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
}

void	t_uint(void)
{
	int	re_ft;
	int	re_io;

	printf("t_uint----------------------\n");
	printf("1)\n");
	re_ft = ft_printf("%u\n", 10);
	re_io = printf("%u\n", 10);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("2)\n");
	re_ft = ft_printf("%u\n", 0);
	re_io = printf("%u\n", 0);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("3)\n");
	re_ft = ft_printf("%u\n", UINT_MAX);
	re_io = printf("%u\n", UINT_MAX);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	printf("4)\n");
	re_ft = ft_printf("%u%u\n", 0, 255);
	re_io = printf("%u%u\n", 0, 255);
	// return value + 1(\n)
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
}

void	t_hex_lower(void)
{
	const int	n = 200;
	int			count_ft;
	int			count_io;

	printf("t_hex_lower----------------------------\n");
	count_ft = 0;
	count_io = count_ft;
	int re_io, re_ft;
	while (count_ft++ < n && count_io++ < n)
	{
		re_ft = printf("%x\n", count_ft);
		re_io = printf("%x\n", count_io);
		if (re_ft == re_io)
			printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
		else
			printf("\e[41mre_ft=%i, re_io=%i\n\e[0m", re_ft, re_io);
	}                                 // ok
	re_ft = printf("%x\n", UINT_MAX); // ok
	re_io = printf("%x\n", UINT_MAX);
	if (re_ft == re_io)
		printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	else
		printf("\e[41mre_ft=%i, re_io=%i\n\e[0m", re_ft, re_io);
}
void	t_hex_upper(void)
{
	const int	n = 200;
	int			count_ft;
	int			count_io;

	printf("t_hex_upper----------------------------\n");
	count_ft = 0;
	count_io = count_ft;
	int re_io, re_ft;
	while (count_ft++ < n && count_io++ < n)
	{
		re_ft = printf("%X\n", count_ft);
		re_io = printf("%X\n", count_io);
		if (re_ft == re_io)
			printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
		else
			printf("\e[41mre_ft=%i, re_io=%i\n\e[0m", re_ft, re_io);
	}                                 // ok
	re_ft = printf("%X\n", UINT_MAX); // ok
	re_io = printf("%X\n", UINT_MAX);
	if (re_ft == re_io)
		printf("re_ft=%i, re_io=%i\n", re_ft, re_io);
	else
		printf("\e[41mre_ft=%i, re_io=%i\n\e[0m", re_ft, re_io);
}
void	t_ptr(void)
{
	int	i;

	printf("t_ptr--------------------------------------\n");
	i = 0;
	int re_io, re_ft;
	printf("1)\n");
	re_ft = ft_printf("%p\n", &i);
	re_io = printf("%p\n", &i);
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io); // ok
	printf("2)\n");
	re_ft = ft_printf("%p\n", NULL);
	re_io = printf("%p\n", NULL);
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io); // ok
}
void	t_percent(void)
{
	printf("t_percent------------------------------\n");
	int re_io, re_ft;
	printf("1)\n");
	re_ft = ft_printf("ft<%%\n>");
	re_io =    printf("io<%%\n>");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io); // OK

	printf("2)\n");
	re_ft = ft_printf("ft<%%%\n>");
	re_io =    printf("io<%%%\n>");//
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io); // ok
	
	printf("3)\n");
	re_ft = ft_printf("ft<%%%#%%%#%\n>");
	re_io =    printf("io<%%%#%%%#%\n>");
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io); // 
}

void	t_error(void)
{
	printf("t_error------------------------------\n");
	int re_io, re_ft;
	printf("1)\n");
	re_ft = ft_printf("ft<%%\n>", 10);
	re_io =    printf("io<%%\n>", 10);
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io); // 
}

void	t_x(void)
{
	int	re_ft;
	int	re_io;

	printf("t_x----------------------------------------\n");
	re_ft = ft_printf("%s%c%i\n", "ABC", 'd', 999);
	re_io = printf("%s%c%i\n", "ABC", 'd', 999);
	printf("re_ft=%i, re_io=%i\n", re_ft, re_io); // ok
}
int	main(void)
{
	t_null();
	t_char();
	t_str();
	t_str_and_char();
	t_int();
	t_uint();
	t_hex_lower();
	t_hex_upper();
	t_ptr();
	t_percent();
	t_error();
	t_x();
}
