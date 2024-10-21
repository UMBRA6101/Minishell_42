/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:38:34 by rafaria           #+#    #+#             */
/*   Updated: 2024/10/18 10:23:44 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../includes/minishell.h"
#include "../includes/libft.h"

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	error(int i, char *str)
{
	if (i == 0)
		exit(EXIT_FAILURE);
	if (i == 1)
		write(2, "Wrong arguments\n", 17);
	if (i == 2)
	{
		write(2, "Command not found : ", 21);
		ft_putchar(str);
		write(2, "\n", 2);
		return ;
	}
	if (i == 3)
	{
		write(2, "no such file or directory : ", 29);
		ft_putchar(str);
		write(2, "\n", 2);
		return ;
	}
	exit(EXIT_FAILURE);
}

void	execute(char *string, char **envp)
{
	int		i;
	char	*chemin;
	char	*path;
	char	**cmd;

	chemin = "/usr/bin/";
	path = NULL;
	cmd = ft_split(string, ' ');
	if (!cmd || !cmd[0])
		error(0, NULL);
	path = ft_strjoin(chemin, cmd[0], 0);
	if (!path || access(path, F_OK & X_OK) != 0)
	{
		i = 0;
		error(2, cmd[0]);
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
	final_execute(path, cmd, envp);
	return ;
}

void	final_execute(char *path, char **cmd, char **envp)
{
	int	i;

	i = 0;
	if (execve(path, cmd, envp) == -1)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		free(path);
		error(0, NULL);
	}
}

// char	*find_path(char *cmd, char **envp)
// {
// 	int		i;
// 	char	*path;
// 	char	*part_path;
// 	char	**paths;

// 	i = 0;
// 	while (ft_strnstr(envp[i], "PATH", 4) == 0)
// 		i++;
// 	paths = ft_split(envp[i] + 5, ':');
// 	i = 0;
// 	while (paths[i])
// 	{
// 		part_path = ft_strjoin(paths[i], "/");
// 		path = ft_strjoin(part_path, cmd);
// 		free(part_path);
// 		if (access(path, F_OK & X_OK) == 0)
// 			return (path);
// 		free(path);
// 		i++;
// 	}
// 	i = 0;
// 	while (paths[i])
// 		free(paths[i]);
// 	free(paths);
// 	return (NULL);
// }
// int	main(int ac, char **av, char **envp)
// {
// 	int		fd[2];
// 	pid_t	pid1;

// 	if (ac == 5)
// 	{
// 		if (pipe(fd) == -1)
// 			error();
// 		pid1 = fork();
// 		if (pid1 == -1)
// 			error();
// 		first_process(av, envp, fd);
// 		waitpid(pid1, NULL, 0);
// 		second_process(av, envp, fd);
// 	}
// 	else
// 		write(2, "Bad arguments, do better\n", 26);
// 	return (0);
// }