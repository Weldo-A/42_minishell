/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:58 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/03 16:06:45 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp;
	char	tmp_modulo;

	if (n >= 0)
	{
		if (n < 10)
		{
			tmp = n + 48;
			ft_putchar_fd(tmp, fd);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			tmp_modulo = (n % 10) + 48;
			ft_putchar_fd(tmp_modulo, fd);
		}
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
}
