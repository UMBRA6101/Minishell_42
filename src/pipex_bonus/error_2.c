/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:08:16 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/23 03:27:34 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_enoent_error(char *cmd, char **args, int variable)
{
	display_error_message(cmd, NULL, ENOENT, args);
	if (variable == 1)
		write_temp_file(TMP_FILES, 127);
	else if (variable == 2)
		write_temp_file(TMP_FILES, 1);
}

void	handle_eisdir_error(char *cmd, char **args, int variable)
{
	display_error_message(cmd, NULL, EISDIR, args);
	if (variable == 1)
		write_temp_file(TMP_FILES, 126);
}

void	handle_enotdir_error(char *cmd, char *mess, char **args, int variable)
{
	display_error_message(cmd, mess, ENOTDIR, args);
	if (variable == 1)
		write_temp_file(TMP_FILES, 127);
	else if (variable == 2)
		write_temp_file(TMP_FILES, 126);
}

void	handle_eacces_error(char *cmd, char *mess, char **args, int variable)
{
	display_error_message(cmd, mess, EACCES, args);
	if (variable == 1)
		write_temp_file(TMP_FILES, 126);
	else if (variable == 2)
		write_temp_file(TMP_FILES, 1);
}

void	handle_command_not_found(char *cmd, int variable)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	if (variable == 1)
		write_temp_file(TMP_FILES, 127);
}
