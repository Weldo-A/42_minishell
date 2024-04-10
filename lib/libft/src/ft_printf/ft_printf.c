/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:46:59 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/29 12:30:08 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] == 37 && ft_strchr("csdiupxX%", format[i + 1]))
		{
			i++;
			count += ft_format_hub(arg, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
