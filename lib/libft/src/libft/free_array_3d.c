/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:17:41 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/12 17:23:57 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    free_array_3d(char ***array)
{
        int     i;

        i = 0;
        while (array[i])
        {
                free_array_2d(array[i]);
                i++;
        }
        free(array);
        array = NULL;
}
