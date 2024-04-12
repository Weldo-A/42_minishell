/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:55:08 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/12 16:15:44 by aboulore         ###   ########.fr       */
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

void	sigquit_handler(int signum)
{
	if (signum != SIGQUIT)
		return ;
	sigflag = signum;
}

int	init_signal(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	ft_bzero(&sigint, sizeof(sigint));
	ft_bzero(&sigquit,sizeof(sigquit));
	sigint.sa_handler = &sigint_handler;
	sigquit.sa_handler = &sigquit_handler;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
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
	inputs = NULL;
	while (1)
	{
		cle = readline("$ ");
		if (!cle)
		{
			free(cle);
			break ;
		}
		if (ft_strlen(cle) > 0 && sigflag != SIGINT)
		{
			add_history(cle);
		}
		if (ft_strlen(cle) > 0)
			parsing(cle, &inputs);
		free(cle);
	}
	free_before_id(inputs);
	return (0);
}
