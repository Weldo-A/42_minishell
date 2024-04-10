/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:45:54 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/09 18:26:25 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal_ptr;
	size_t	nsize;

	nsize = nmemb * size;
	if (size && nsize / size != nmemb)
		return (NULL);
	cal_ptr = malloc(sizeof(char) * nsize);
	if (!(cal_ptr))
		return (NULL);
	ft_bzero(cal_ptr, nsize);
	return (cal_ptr);
}
