/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:33:37 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/11 13:29:10 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing(char *str, t_list **inputs)
{
	size_t		input_nb;
	char	**inputs_arr;

	inputs = NULL;
	inputs_arr = newlines(str, &input_nb);
	print_2d_array(inputs_arr);
	break_into_words(inputs_arr, inputs, input_nb); //according to what is a word sep-metach THAT ARE NOT ESCAPED, cree le tableau de input(t_list), pour l'instant pas de liste de t_list = simples commandes dans pipes
//	identifcation;
}
