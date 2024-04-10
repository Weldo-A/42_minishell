/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:55:08 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/10 18:18:25 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile int	sigflag = 0;
char	*cle = NULL;

void	sigint_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	rl_on_new_line();
	rl_replace_line("\n", 1);
	rl_redisplay();
	sigflag = signum;
	free(cle);
	exit(128 + sigflag); //recuper pr faire 128 + n avec n = num du signal
}

int	init_signal(void)
{
	struct sigaction	sigint;

	ft_bzero(&sigint, sizeof(sigint));
	sigint.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigint, NULL);
	return (1);
}

int	main(void)
{
//	char *cle;

	init_signal();
	while (1)
	{
	//	if (sigflag == SIGINT)
	//	{
	//		free(cle);
	//		exit(128 + sigflag); //recuper pr faire 128 + n avec n = num du signal
	//	}
		cle = readline("$ ");
		if (ft_strlen(cle) > 0)
			add_history(cle);
//		printf("%s\n", rl_line_buffer);
	}
	return (0);
}
