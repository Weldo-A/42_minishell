/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totrash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:54:38 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/12 07:36:00 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_2d_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putstr("NEW_INPUT: ");
		ft_putstr(str[i]);
		i++;
	}
}

void	print_unidentified_tokens(size_t input_nb, t_list *inputs)
{
	size_t	i;
	size_t	j;
	//size_t	k;
	size_t	size_input;
	//size_t	size_cmd;
	t_list	*tmp;
	t_wd_desc	*word;

	i = 0;
	printf("\nDATA BEFORE IDENTIFICATION\n");
	while (i < input_nb)
	{
		printf("\nINPUT N°%zu\n", i);
		tmp = &inputs[i];
		size_input = ft_lstsize(tmp);
		j = 0;
		while (j < size_input)
		{
			printf("\nTOKEN N°%zu\n", j);
		//	k = 0;
			word = (t_wd_desc*)tmp->content;
			printf("%s\n", word->word);
			tmp = tmp->next;
			j++;
		}
		i++;
	}
}
