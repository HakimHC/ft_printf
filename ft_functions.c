/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 03:06:11 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/13 14:09:00 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_intlen(long n)
{
	if (!n)
		return (1);
	return (0 + ft_intlen(n / 10));
}

int	ft_putnbr(long n, int *len)
{
	long	i;

	i = n;
	if (n < 0)
	{
		n = -n;
		*len += ft_putchar('-');
	}
	if (n / 10 != 0)
		ft_putnbr(n / 10, len);
	*len += ft_putchar((n % 10) + 48);
	return (0);
}
