/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:56:48 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/15 14:36:23 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strllen(const char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i] && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	if (!dst && size == 0)
		return (0);
	len_dst = ft_strllen(dst, size);
	len_src = ft_strlen(src);
	j = len_dst;
	i = 0;
	if (len_dst < size && size != 0 && src)
	{
		while (i < (size - len_dst - 1) && src[i])
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (len_src + len_dst);
}
