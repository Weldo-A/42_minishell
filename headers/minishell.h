/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:11:16 by aboulore          #+#    #+#             */
/*   Updated: 2024/04/11 10:52:27 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <termios.h>
# include "libft.h"

typedef enum e_bool { false, true }	t_bool;

typedef struct s_wd_desc
{
	char	*word;
	int		flags;
}	t_wd_desc;

typedef struct s_wd_lst
{
	t_wd_lst	*next;
	t_wd_desc	*word;
}	t_wd_lst;

typedef struct s_cmd_lst
{
	t_cmd_lst	*next;
	t_wd_lst	*cmd;
}	t_cmd_lst;

#endif
