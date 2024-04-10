/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlclprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:07:43 by aboulore          #+#    #+#             */
/*   Updated: 2024/02/14 11:31:57 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlclprint(t_dlcl *lst)
{
	t_dlcl	*temp;

	ft_printf("\nList :\n");
	if (lst == NULL)
	{
		ft_printf("\nlst empty\n");
		return ;
	}
	temp = lst;
	while (temp->next != lst)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
	ft_printf("%d\n", temp->content);
}
