/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:42:36 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/22 16:11:41 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	if (n < 10 && n >= 0)
		return (ft_putchar(n + 48));
	else if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	return (ft_putnbr(n / 10) + ft_putchar((n % 10) + 48));
}

int	ft_putnbr_u(unsigned int n)
{
	if (n < 10)
		return (ft_putchar(n + 48));
	return (ft_putnbr_u(n / 10) + ft_putchar((n % 10) + 48));
}

int	ft_putnbr_xup(unsigned int n)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putchar(n + 48));
		else if (n < 16 && n > 9)
			return (ft_putchar(n + 55));
	}
	else if (n >= 16 && n % 16 < 10)
		return (ft_putnbr_xup(n / 16) + ft_putchar((n % 16) + 48));
	else if (n >= 16 && n % 16 < 16 && n % 16 > 9)
		return (ft_putnbr_xup(n / 16) + ft_putchar((n % 16) + 55));
	return (0);
}
