/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:17:49 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/12 07:41:40 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
static t_bool	is_escaped(char *meta, t_esc *esc_status)
{
	char	a;

	a = *meta;
	
}*/

static void	check_quote(t_esc *esc_status, char *str)
{
	size_t	i;
	
	i = 0;
	if (!ft_strchr("\'\"", str[i]))
		return ;
	if (esc_status->is_quoted == false && ft_strchr("\'\"", str[i]) \
		&& ft_strchr(&str[i + 1], str[i]))
	{
		esc_status->is_quoted = true;
		if (str[i] == '\'')
			esc_status->is_simplequote = true;
		return ;
	}
	else if ((esc_status->is_simplequote == true && str[i] == '\"') || \
		(esc_status->is_simplequote == false && str[i] == '\"'))
		return ;
	esc_status->is_quoted = false ;
}

static t_list	*input_into_words(char *str)
{
	t_list		*words_list;
	t_esc		esc_status;
	t_wd_desc	word;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	words_list = NULL;
	esc_status.is_quoted = false;
	while (str[i])
	{
		check_quote(&esc_status, &str[i]);
		if (ft_strchr("|&<>() \t", str[i]) \
			&& esc_status.is_quoted == false)
		{
			if (j != i)
			{
				word.word = ft_substr(str, j, i - j);
				ft_lstadd_back(&words_list, ft_lstnew((void *)&word));
			}
			if (!ft_isspace(str[i]))
			{
				if (!ft_strchr("()", str[i]) && str[i + 1] == str[i])
				{
					word.word = ft_substr(&str[i], 0, 2);
					i++;
				}
				else
					word.word = ft_substr(&str[i], 0, 1);
				ft_lstadd_back(&words_list, ft_lstnew((void *)&word));
			}
			j = i + 1;
		}
		i++;
	}
	if (!ft_isspace(str[i - 1]))
	{
		if (j != i)
		{
			word.word = ft_substr(str, j, i - j);
			ft_lstadd_back(&words_list, ft_lstnew((void *)&word));
		}
	}
	return (words_list);
}

void	break_into_words(char **inputs_array, t_list **inputs, \
		size_t input_nb)
{
	size_t	i;

	i = 0;
	*inputs = malloc(sizeof(t_list *) * input_nb);
	while (i < input_nb)
	{
		inputs[i] = input_into_words(inputs_array[i]);
		free(inputs_array[i]);
		i++;
	}
}
