/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:18:30 by aboulore          #+#    #+#             */
/*   Updated: 2024/01/18 19:45:30 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*start_next_line(char *final, char *stash)
{
	size_t	i;

	i = 0;
	stash = NULL;
	while (final[i] != '\n' && final[i])
		i++;
	if (final[i] == 0 || final[i + 1] == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_strdup(&final[i + 1]);
	final[i + 1] = 0;
	return (stash);
}

char	*fill_final(char *stash, int fd)
{
	char	*tmp;
	char	*buf;
	int		m;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	m = read(fd, buf, BUFFER_SIZE);
	while (m > 0)
	{
		buf[m] = 0;
		if (!stash)
			stash = ft_calloc(1, 1);
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
		m = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
	if (m == -1)
		return (NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*final;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	final = fill_final(stash[fd], fd);
	if (!final)
		return (NULL);
	stash[fd] = start_next_line(final, stash[fd]);
	return (final);
}
