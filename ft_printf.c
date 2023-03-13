/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:58:56 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/13 14:54:08 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int	flag_check(char flag, va_list args, int *len)
{
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (flag == 'i' || flag == 'd')
		return (ft_putnbr(va_arg(args, int), len));
	if (flag == 'x' || flag == 'X' || flag == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int ), flag, len));
	if (flag == '%')
		return (ft_putchar('%'));
	if (flag == 'p')
		return (ft_putnbr_u(va_arg(args, unsigned long int), flag, len));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += flag_check(s[i + 1], args, &len);
			i += 2;
		}
		else
		{
			write(1, (s + i), 1);
			len++;
			i++;
		}
	}
	return (len);
}
//
// int	main(void)
// {
//  	ft_printf("LEN: %i\n", ft_printf("%p\n", (void *)-14523));
//  	ft_printf("LEN: %i\n", printf("%p\n", (void *) -14523));
// }