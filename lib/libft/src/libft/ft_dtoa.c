/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:18:31 by aboulore          #+#    #+#             */
/*   Updated: 2024/03/20 12:55:12 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_final(char *istr, char *dstr, double dpart)
{
	char	*tmp;

	tmp = ft_strjoin(istr, ".");
	free(istr);
	istr = ft_strjoin(tmp, dstr);
	free(tmp);
	free(dstr);
	if (dpart < 0)
	{
		dstr = ft_strjoin("-", istr);
		free(istr);
		return (dstr);
	}
	return (istr);
}

char	*ft_dtoa(double n, int afterpoint)
{
	char	*istr;
	char	*dstr;
	char	*final;
	int		ipart;
	double	dpart;

	ipart = (int)n;
	dpart = n - (double)ipart;
	istr = ft_itoa(ipart);
	dpart = dpart * pow(10, afterpoint);
	dstr = ft_itoa(abs((int)dpart));
	final = create_final(istr, dstr, dpart);
	return (final);
}
