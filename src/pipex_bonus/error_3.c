/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:10:11 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/23 03:27:25 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_error_message(char *cmd, char *mess, int errno_code,
		char **args)
{
	char	*return_sterror;

	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	if (args != NULL)
	{
		display_args(args);
		write(2, ": ", 2);
	}
	if (mess != NULL)
		write(2, mess, ft_strlen(mess));
	else
	{
		return_sterror = strerror(errno_code);
		write(2, return_sterror, ft_strlen(return_sterror));
	}
	write(2, "\n", 1);
}

void	handle_eloop_error(char *cmd, char **args, int variable)
{
	display_error_message(cmd, NULL, ELOOP, args);
	if (variable == 1)
		write_temp_file(TMP_FILES, 127);
	else if (variable == 2)
		write_temp_file(TMP_FILES, 1);
}

void	handle_enametoolong_error(char *cmd, char **args, int variable)
{
	display_error_message(cmd, NULL, ENAMETOOLONG, args);
	if (variable == 1)
		write_temp_file(TMP_FILES, 127);
	else if (variable == 2)
		write_temp_file(TMP_FILES, 1);
}
