/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:53 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/13 01:24:11 by aboulore         ###   ########.fr       */
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

void	free_before_id(t_list *inputs, size_t in_nb)
{
	size_t	i;
	t_list	*lst;

	i = 0;
	while (i < in_nb)
	{
	  printf("\nin\n");
		lst = &inputs[i];
		ft_lstclear(&lst, &del_wddesc);
		free(*inputs[i]);
		i++;
	}
}
