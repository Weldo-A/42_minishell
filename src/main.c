/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:55:08 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/11 12:51:07 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile int	sigflag = 0;

void	sigint_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	sigflag = signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	init_signal(void)
{
	struct sigaction	sigint;

	ft_bzero(&sigint, sizeof(sigint));
	sigint.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigint, NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*inputs;

	char *cle;
	(void)argv;
	if (argc != 1)
		exit(0);
	init_signal();
	while (1)
	{
		cle = readline("$ ");
		if (ft_strlen(cle) > 0 && sigflag != SIGINT)
			add_history(cle);
		parsing(cle, &inputs);
		free(cle);
	}
	return (0);
}
