/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:02:17 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/15 15:05:33 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_arrays(char const *s, char c)
{
	int	i;
	int	len_split;

	i = 0;
	len_split = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			len_split++;
		i++;
	}
	return (len_split);
}

static char	**free_split(char **split, int len_split)
{
	int	i;

	i = 0;
	while (i < len_split)
	{
		free(split[i]);
		i++;
	}
	split = NULL;
	return (split);
}

static char	**fill_split(char **split, char const *s, char c, int len_split)
{
	int	j;
	int	i;
	int	len_array;
	int	start;

	i = 0;
	j = 0;
	while (j < len_split)
	{
		len_array = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
		{
			len_array++;
			i++;
		}
		split[j] = ft_substr(s, start, len_array);
		if (!split[j])
			split = free_split(split, len_split);
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		len_split;

	if (!s)
		return (0);
	len_split = count_arrays(s, c);
	split = malloc(sizeof(char *) * (len_split + 1));
	if (split == NULL)
		return (NULL);
	split = fill_split(split, s, c, len_split);
	if (!split)
		split = free_split(split, len_split);
	return (split);
}
