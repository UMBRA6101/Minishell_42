/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:38:34 by rafaria           #+#    #+#             */
/*   Updated: 2024/10/29 15:30:07 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void handle_heredoc(const char *delimiter)
{
    char *line;
    int   pipe_fds[2];

    if (pipe(pipe_fds) == -1)
    {
        perror("Erreur lors de la création du pipe");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        line = readline("> ");
        if (!line)
        {
            printf("CTRL D PRESSED \n");
			exit(1);
        }
        if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
        {
            free(line);
            break;
        }
        write(pipe_fds[1], line, ft_strlen(line));
        write(pipe_fds[1], "\n", 1);
        free(line);
    }
    close(pipe_fds[1]);
    dup2(pipe_fds[0], STDIN_FILENO);
    close(pipe_fds[0]);
}


void handle_redirection(t_data_rule data)
{
    int fd;

    if (ft_strncmp(data.oper, "<", 2) == 0)
    {
        fd = open(data.targetfile, O_RDONLY);
        if (fd == -1)
        {
            perror("Erreur entree ");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    else if (ft_strncmp(data.oper, "<<", 3) == 0)
    {
        handle_heredoc(data.targetfile);
    }
    else if (ft_strncmp(data.oper, ">", 2) == 0)
    {
        fd = open(data.targetfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            perror("Erreur entree");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
    else if (ft_strncmp(data.oper, ">>", 3) == 0)
    {
        fd = open(data.targetfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd == -1)
        {
            perror("Erreur ouverture sortie");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
}

void wait_for_children(void)
{
    int status;

    while (wait(&status) > 0)
    {
        // attends
    }
}

void error(int i, char *str)
{
    if (i == 1)
    {
        write(2, "Wrong arguments\n", 17);
    }
    else if (i == 2)
    {
        write(2, "Command not found : ", 21);
        if (str)
        {
            write(2, str, strlen(str));
        }
        write(2, "\n", 1);
    }
    else if (i == 3)
    {
        write(2, "no such file or directory : ", 29);
        if (str)
        {
            write(2, str, strlen(str));
        }
        write(2, "\n", 1);
    }
    exit(EXIT_FAILURE);
}
void    free_command(char **cmd)
{
    int i;

    i = 0;
    if (!cmd)
        return;
    while (cmd[i])
    {
        free(cmd[i]);
        i++;
    }
    free(cmd);
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