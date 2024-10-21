/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:45:57 by raphox            #+#    #+#             */
/*   Updated: 2024/10/21 15:07:28 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../includes/minishell.h"
#include "../includes/libft.h"

//------------------------------------------------------------------------------



void close_pipes(int *pipes)
{
    close(pipes[0]);
    close(pipes[1]);
}

void handle_child_process(char *cmd, char **env, int *input_fd, int *p_fd, int is_last_cmd)
{
    if (input_fd != NULL)
    {
        dup2(*input_fd, STDIN_FILENO);
        close(*input_fd);
    }
    if (!is_last_cmd)
    {
        close(p_fd[0]);
        dup2(p_fd[1], STDOUT_FILENO);
    }
    close(p_fd[1]);
    execute(cmd, env);
}

void handle_parent_process(int *input_fd, int *p_fd, int is_last_cmd)
{
    if (input_fd != NULL)
        close(*input_fd);
    if (!is_last_cmd)
    {
        close(p_fd[1]);
        *input_fd = p_fd[0];
    }
    else
    {
        close_pipes(p_fd);
    }
}

void do_pipe(char *cmd, char **env, int *input_fd, int is_last_cmd)
{
    pid_t pid;
    int p_fd[2];

    if (pipe(p_fd) == -1)
        exit(0);
    pid = fork();
    if (pid == -1)
        exit(0);
    if (pid == 0)
    {
        handle_child_process(cmd, env, input_fd, p_fd, is_last_cmd);
    }
    else
    {
        handle_parent_process(input_fd, p_fd, is_last_cmd);
    }
}

void wait_for_children(void)
{
    int status;

    while (wait(&status) > 0)
        ;
}

int pipex(int ac, char **av, char **envp)
{
    int index;
    int input_fd;

    input_fd = -1;
    if (ac < 3)
    {
        write(2, "Usage: ./pipex cmd1 cmd2 ... cmdn\n", 35);
        return (1);
    }
    index = 1;
    while (index < ac - 1)
    {
        do_pipe(av[index], envp, &input_fd, 0);
        index++;
    }
    do_pipe(av[ac - 1], envp, &input_fd, 1);
    wait_for_children();
    return (0);
}


