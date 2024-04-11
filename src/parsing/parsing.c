/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:33:37 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/11 12:57:43 by aboulore         ###   ########.fr       */
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
//	words; //according to what is a word sep-metach THAT ARE NOT ESCAPED
//	identifcation;
}
