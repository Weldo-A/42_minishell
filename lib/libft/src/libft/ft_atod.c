/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:45:43 by aboulore          #+#    #+#             */
/*   Updated: 2024/03/20 12:08:15 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	go_to_digits(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || \
		str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
			break ;
		i++;
	}
	return (i);
}

static double	detect_neg(char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

static double	frac_part(char *str, int i, double p)
{
	double	dec;

	dec = 0;
	while (ft_isdigit(str[i]) && str[i])
	{
		p /= 10;
		dec = dec + (str[i] - 48) * p;
		i++;
	}
	return (dec);
}

double	ft_atod(char *str)
{
	int		i;
	double	dec;
	double	res;
	double	neg;

	res = 0;
	neg = detect_neg(str);
	dec = 0;
	i = go_to_digits(str);
	while (ft_isdigit(str[i]) && str[i])
	{
		if (ft_isdigit(str[i]))
			res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	dec = frac_part(str, i, 1);
	return (neg * (dec + res));
}
