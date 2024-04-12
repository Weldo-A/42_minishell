/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:53 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/12 16:24:11 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_wddesc(void *word)
{
	t_wd_desc	*del;

	del = (t_wd_desc *)word;
	free(del->word);
	free(del);
}

void	free_before_id(t_list *inputs)
{
	size_t	i;
	t_wd_desc	*in_nb;

	i = 1;
	in_nb = (t_wd_desc *)inputs[0].content;
	while (i <= (size_t)in_nb->flags)
	{
		ft_lstclear(&(&inputs)[i], &del_wddesc);
		i++;
	}
	free(inputs);
}
