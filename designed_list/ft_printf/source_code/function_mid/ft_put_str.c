/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:06:26 by skazama           #+#    #+#             */
/*   Updated: 2025/12/20 17:08:56 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_put_null(void)
{
	const char	s[] = "(null)";
	int			i;

	i = 0;
	while (s[i] != '\0')
		i += ft_put_char(s[i]);
	return (i);
}

int	ft_put_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_put_null());
	while (s[i] != '\0')
		i += ft_put_char(s[i]);
	return (i);
}
