/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_command_builder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:14:05 by raphox            #+#    #+#             */
/*   Updated: 2025/01/25 17:15:28 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*build_command(char *command)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (command == NULL)
		return (NULL);
	if (is_directory(command) == 1 && check_slash(command) == 1)
		return (errno = 21, NULL);
	while (command[i] != '\0')
	{
		if (command[i] == '/')
			found = i + 1;
		i++;
	}
	if (found != 0)
	{
		if (access(command, F_OK | X_OK) == -1)
			return (NULL);
		return (ft_strdup(command + found));
	}
	else
		return (ft_strdup(command));
}

void	free_command_array(char **cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		return ;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

char	**build_execution(t_data_rule data)
{
	char	**cmd;
	int		index;
	int		options_count;

	count_options(data.options, &options_count);
	cmd = malloc(sizeof(char *) * (1 + options_count + data.nbr_args + 1));
	if (!cmd)
		return (write(2, "Error: Memory allocation failed\n", 33), NULL);
	index = 0;
	cmd[index] = build_command(data.command);
	if (!cmd[index++])
		return (free_command_array(cmd), NULL);
	index = append_elements(cmd, data.options, index, "option");
	if (index == -1)
		return (NULL);
	index = append_elements(cmd, data.arguments, index, "argument");
	if (index == -1)
		return (NULL);
	cmd[index] = NULL;
	return (cmd);
}

int	append_elements(char **cmd, char **elements, int index, char *type)
{
	int	i;

	i = 0;
	if (!elements)
		return (index);
	while (elements[i])
	{
		cmd[index] = ft_strdup(elements[i++]);
		if (!cmd[index++])
		{
			write(2, "Error: Failed to duplicate ", 27);
			write(2, type, ft_strlen(type));
			write(2, "\n", 1);
			free_command_array(cmd);
			return (-1);
		}
	}
	return (index);
}
