/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:07:52 by skazama           #+#    #+#             */
/*   Updated: 2025/12/25 22:12:14 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> //va_arg..
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>  //printf
#include <stdlib.h> //size_t
#include <unistd.h>
#define ERROR_FORMAT -1

enum			e_case
{
	lower,
	upper
};

int				ft_printf(const char *format, ...);
int				ft_put_char(char c);
int				ft_put_null(void);
int				ft_put_str(char *s);
int				ft_put_nbr(int n);
int				ft_put_unsignednbr(unsigned int un);
int				ft_put_hexadecimal(unsigned int un, bool letter_case);
int				ft_put_ptr(void *ptr);
unsigned int	ft_abs(const int n);
int				count_digit(const int n, const unsigned int base);
int				count_digit_unsigned(unsigned int un, const unsigned int base);
