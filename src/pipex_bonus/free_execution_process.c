/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_execution_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:00:28 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/27 13:14:23 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_execution_process(t_data_rule *struct_data,
		t_struc_process struct_exec)
{
	if (struct_exec.cmd != NULL)
	{
		free_env(struct_exec.cmd);
	}
	if (struct_exec.env != NULL)
	{
		free_env(struct_exec.env);
		struct_exec.env = NULL;
	}
	if (struct_data != NULL)
	{
		killer_request(struct_data);
	}
}

void	check_redirections_in_cmd(t_data_rule *struct_data, t_data_rule data,
		t_struc_process struct_exec)
{
	struct_exec.cmd = NULL;
	if (check_if_in_builtins(data) == -1)
	{
		free_execution_process(struct_data, struct_exec);
		exit(ask_tmp_files());
	}
	if (data.input != NULL && check_whole_entry_redirections(data) == -1)
	{
		display_error(data.command, NULL, data.arguments, 2);
		free_execution_process(struct_data, struct_exec);
		exit(ask_tmp_files());
	}
	if (data.oper != NULL && check_whole_exit_redirections(data) == -1)
	{
		display_error(data.command, NULL, data.arguments, 2);
		free_execution_process(struct_data, struct_exec);
		exit(ask_tmp_files());
	}
	else
		handle_redirection(data);
}

void	check_cmd_in_cmd(char **pathname, t_data_rule *struct_data,
		t_data_rule data, t_struc_process *struct_exec)
{
	struct_exec->cmd = build_execution(data);
	if (struct_exec->cmd == NULL)
	{
		display_error(data.command, NULL, data.arguments, 1);
		free_execution_process(struct_data, *struct_exec);
		exit(ask_tmp_files());
	}
	if (check_if_in_builtins(data) == 0)
	{
		*pathname = find_path(data.command, struct_exec->cmd[0],
				struct_exec->env);
		if (*pathname == NULL && check_if_in_builtins(data) != 42)
		{
			errno = 0;
			display_error(struct_exec->cmd[0], "cmd not found", NULL, 1);
			free_execution_process(struct_data, *struct_exec);
			return (free(*pathname), exit(ask_tmp_files()));
		}
	}
	if (check_if_in_builtins(data) == 1 || check_if_in_builtins(data) == 42)
	{
		exec_builtins(data, struct_exec->env);
		free_execution_process(struct_data, *struct_exec);
		exit(ask_tmp_files());
	}
}
