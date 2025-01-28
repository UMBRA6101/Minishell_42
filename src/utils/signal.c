/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:52:10 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/28 17:01:51 by umbra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_traitment(int sig)
{
	if (!kill(g_pid, sig))
	{
		if (sig == SIGINT)
		{
			write_temp_file(TMP_FILES, 1024);
			ft_putchar_fd('\n', 1);
		}
		else if (sig == SIGQUIT)
		{
			ft_putstr_fd("Quit (core dumped)\n", 0);
			write_temp_file(TMP_FILES, 1025);
		}
	}
}

void	signal_treatment(int sig)
{
	if ((sig == SIGINT || sig == SIGQUIT) && g_pid != 0)
		process_traitment(sig);
	else if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		write_temp_file(TMP_FILES, 1024);
	}
	else if (sig == SIGQUIT)
	{
		rl_redisplay();
		rl_on_new_line();
		printf("  \b\b");
	}
}
