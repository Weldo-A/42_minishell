/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:33:37 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/24 10:50:01 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	parsing(char *str, t_list **inputs)
{
	size_t		input_nb;
	char		**inputs_arr;

//lexer
	inputs_arr = newlines(str, &input_nb);
	print_2d_array(inputs_arr);
	ft_putstr("\n\n");
	break_into_words(inputs, inputs_arr, input_nb); 
	//word_or_operator(inputs, input_nb);
	print_unidentified_tokens(input_nb, *inputs);

//	identification;

//	parser

	return (input_nb);
}
