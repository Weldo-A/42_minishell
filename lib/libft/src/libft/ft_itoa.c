/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:18:31 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/07 10:55:29 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(int n, int i)
{
	if (n == -2147483648)
		return (11);
	else if (n == 0)
		return (1);
	else if (n < 0)
		return (count_char(-n, i + 1));
	else if (n / 10 == 0)
		return (i + 1);
	return (count_char(n / 10, i + 1));
}

static int	if_neg(int n, char *neg)
{
	if (n < 0)
	{
		n *= -1;
		neg[0] = '-';
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = count_char(n, i);
	str = malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		ft_strlcpy(str, "0", 2);
	else if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	else if (n != -2147483648)
	{
		n = if_neg(n, str);
		str[j] = '\0';
		while (n != 0)
		{
			str[j - 1] = (n % 10) + 48;
			n = n / 10;
			j--;
		}
	}
	return (str);
}
