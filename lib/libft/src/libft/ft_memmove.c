/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:58:16 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/10 16:20:38 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dest2;
	const char	*src2;

	dest2 = dest;
	src2 = src;
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			dest2[i] = src2[i];
			i--;
		}
	}
	else
		dest2 = ft_memcpy(dest, src, n);
	return (dest2);
}
