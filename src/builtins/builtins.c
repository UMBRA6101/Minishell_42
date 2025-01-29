/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:32:59 by raphox            #+#    #+#             */
/*   Updated: 2025/01/29 19:00:31 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**exec_builtins(t_data_rule data, char **envv)
{
	if (data.input != NULL && chk_entry(data.oper[0], data.input) == -1)
	{
		display_error(data.command, NULL, data.arguments, 2);
		return (envv);
	}
	if (data.oper != NULL && check_whole_exit_redirections(data) == -1)
	{
		display_error(data.command, NULL, data.arguments, 2);
		return (envv);
	}
	if (ft_strcmp(data.command, "cd") == 0)
		return (cd(data.command, data.arguments, envv));
	else if (ft_strcmp(data.command, "echo") == 0)
		echo(data.command, data.options, data.arguments);
	else if (ft_strcmp(data.command, "env") == 0)
		display_env(envv);
	else if (ft_strcmp(data.command, "export") == 0)
		return (export(data.command, data.arguments, envv));
	else if (ft_strcmp(data.command, "pwd") == 0)
		pwd();
	else if (ft_strcmp(data.command, "unset") == 0)
		return (unset(data.arguments, envv));
	else if (ft_strcmp(data.command, "exit") == 0)
		built_exit(data.arguments);
	return (envv);
}

int	check_if_in_builtins(t_data_rule struc)
{
	if (ft_strcmp(struc.command, "cd") == 0)
		return (-1);
	else if (ft_strcmp(struc.command, "echo") == 0)
		return (1);
	else if (ft_strcmp(struc.command, "env") == 0)
		return (1);
	else if (ft_strcmp(struc.command, "export") == 0)
		return (-1);
	else if (ft_strcmp(struc.command, "pwd") == 0)
		return (1);
	else if (ft_strcmp(struc.command, "unset") == 0)
		return (-1);
	else if (ft_strcmp(struc.command, "exit") == 0)
		return (42);
	return (0);
}
