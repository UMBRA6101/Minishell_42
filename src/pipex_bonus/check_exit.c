/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:58:04 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/23 02:38:28 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exit(t_data_rule *struct_data, t_data_rule data,
		t_struc_process struct_exec, t_erreur *err)
{
	if (struct_exec.num_commands == 1 && (ft_strncmp(data.command, "exit",
				ft_strlen(data.command)) == 0))
	{
		if (built_exit(data.arguments) == 0)
			return (-1);
		free_env(struct_exec.env);
		killer_request(struct_data);
		free(struct_exec.tab_heredoc);
		err->exit_value = ask_tmp_files();
		unlink(TMP_FILES);
		exit(err->exit_value);
	}
	return (0);
}

int	check_builtins_before_pipe(t_data_rule *struct_data, t_data_rule data,
		t_struc_process struct_exec, t_erreur *err)
{
	if (check_if_in_builtins(data) == -1 || check_if_in_builtins(data) == 42)
	{
		if (check_exit(struct_data, data, struct_exec, err) == -1)
			return (-1);
		if (struct_exec.num_commands == 1)
		{
			struct_exec.env = exec_builtins(data, struct_exec.env);
			if (struct_exec.env == NULL)
				return (-2);
		}
		err->exit_value = ask_tmp_files();
	}
	return (0);
}
