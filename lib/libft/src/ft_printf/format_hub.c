/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:09:16 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/22 16:13:05 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_hub(va_list arg, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (ft_putnbr_xup(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_x(va_arg(arg, unsigned int)));
	else if (c == 'p')
		return (ft_putptr((unsigned long int)va_arg(arg, void *)));
	return (ft_printf("error"));
}
