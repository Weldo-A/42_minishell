/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:17:49 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/11 14:33:33 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_escaped(char *meta, t_esc *esc_status)
{
//depend du char par rapp au statut de quote	
}

static t_list	*input_into_simplecmds(char *str)
{
	t_list	*words_list;
	t_esc	esc_status;
	char	*word;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_strchr("|&<>() \t", str[i]) && is_escaped(&str[i], &esc_status) == false)
		{
			word = ft_substr(//j'assigne le mot
			//si meta n'est pas isspace (is isspace a aj ds libft)	
			//	creer word du meta (et avancer curseur si && etci) tant que str[i] n'est pas un des metas etc
		}
		i++;
	}
	return (words_list);
}

void	break_into_words(char **inputs_array, t_list **inputs, \
		size_t input_nb)
{
	size_t	i;
	t_list	*new;

	i = 0;
	while (i < input_nb)
	{
		new = input_into_simplecmds(inputs_array[i]);
		ft_lstadd_back(inputs, (void *)new);
		free(inputs_array[i]);
		i++;
	}
}
