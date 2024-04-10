/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:43:06 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/10 13:30:09 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*last_node;

	last_node = (t_list *)malloc(sizeof(t_list));
	if (last_node == NULL)
		return (NULL);
	last_node->content = content;
	last_node->next = NULL;
	return (last_node);
}
