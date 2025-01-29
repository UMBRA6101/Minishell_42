/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:37:42 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/29 19:11:08 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_exit_redirections(t_data_rule data, char oper, char *output)
{
	int	fd;

	if (oper == '>')
		fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(output, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		if (oper == '>')
			display_error(data.command, output, data.arguments, 0);
		else if (oper == 'r')
			display_error(data.command, NULL, data.arguments, 0);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	handle_entry_redirections(t_data_rule data, char oper, char *input)
{
	int	fd;

	if (oper == '<')
	{
		fd = open(input, O_RDONLY);
		if (fd == -1)
		{
			display_error(data.command, NULL, data.arguments, 0);
			return (-1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	*find_path_in_paths(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*part_path;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/", 0);
		if (part_path == NULL)
			return (NULL);
		path = ft_strjoin(part_path, cmd, 0);
		free(part_path);
		if (path == NULL)
			return (NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd_brut, char *cmd, char **envv)
{
	int		i;
	char	**paths;
	char	*path;

	if (access(cmd_brut, F_OK | X_OK) == 0)
		return (ft_strdup(cmd_brut));
	i = 0;
	while (envv[i] && ft_strnstr(envv[i], "PATH", 4) == 0)
		i++;
	if (envv[i] == NULL)
		return (NULL);
	paths = ft_split(envv[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
	path = find_path_in_paths(paths, cmd);
	free_split(paths);
	return (path);
}
