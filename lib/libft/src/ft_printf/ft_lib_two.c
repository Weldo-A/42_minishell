/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:48:44 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/22 16:08:19 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(unsigned int n)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putchar(n + 48));
		else if (n < 16 && n > 9)
			return (ft_putchar(n + 87));
	}
	else if (n >= 16 && n % 16 < 10)
		return (ft_putnbr_x(n / 16) + ft_putchar((n % 16) + 48));
	else if (n >= 16 && n % 16 < 16 && n % 16 > 9)
		return (ft_putnbr_x(n / 16) + ft_putchar((n % 16) + 87));
	return (0);
}

static int	ft_putnbr_p(unsigned long int n)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putchar(n + 48));
		else if (n < 16 && n > 9)
			return (ft_putchar(n + 87));
	}
	else if (n >= 16 && n % 16 < 10)
		return (ft_putnbr_p(n / 16) + ft_putchar((n % 16) + 48));
	else if (n >= 16 && n % 16 < 16 && n % 16 > 9)
		return (ft_putnbr_p(n / 16) + ft_putchar((n % 16) + 87));
	return (0);
}

int	ft_putptr(unsigned long int p)
{
	if (p == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbr_p(p));
}
