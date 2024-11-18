/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:22:44 by raphox            #+#    #+#             */
/*   Updated: 2024/11/13 15:27:00 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"


void execute(t_data_rule data, char **envp)
{
    char **cmd = build_command(data);

    if (!cmd[0])
    {
        error(1, NULL);
    }
    if (data.oper != NULL)
    {
        handle_redirection(data);
    }

	if (exec_builtins(data, envp) == 0)
	{
		if (execve(cmd[0], cmd, envp) == -1)
    	{
        	perror("execve");
        	free_command(cmd);
        	exit(EXIT_FAILURE);
    	}
	}
}

void execution_process(t_data_rule data, char **env, int *input_fd, int *p_fd, int is_last_cmd)
{
    if (input_fd != NULL && *input_fd != -1) // si input valid et different = flux d entree dispo
    {
        dup2(*input_fd, STDIN_FILENO); // ancienne entree
        close(*input_fd);
    }

    if (!is_last_cmd)
    {
        close(p_fd[0]);
        dup2(p_fd[1], STDOUT_FILENO);
        close(p_fd[1]);
    }

    execute(data, env);
}

void second_process(int *input_fd, int *p_fd, int is_last_cmd)
{
    if (input_fd != NULL && *input_fd != -1)
    {
        close(*input_fd);
    }

    if (is_last_cmd == 0) // pas la derniere commande
    {
        close(p_fd[1]);
        *input_fd = p_fd[0];
    }
    else
    {
        close(p_fd[0]);
        close(p_fd[1]);
    }
}

void do_pipe(t_data_rule data, char **env, int *input_fd, int is_last_cmd)
{
    pid_t pid;
    int p_fd[2];

    if (pipe(p_fd) == -1)
    {
        exit(1);
    }

    pid = fork(); // dedoublement du code
    if (pid == -1)
    {
        exit(1);
    }
    if (pid == 0)
    {
        execution_process(data, env, input_fd, p_fd, is_last_cmd);
    }
    else
    {
        second_process(input_fd, p_fd, is_last_cmd);
    }
}

int pipex(t_data_rule *data, int num_commands, char **envp)
{
    int input_fd = -1;
    int i = 0;

    while (i < num_commands)
    {
        int is_last_command;

        if (i == num_commands - 1)
        {
            is_last_command = 1;
        }
        else
        {
            is_last_command = 0;
        }

        do_pipe(data[i], envp, &input_fd, is_last_command);
        i++;
    }
    wait_for_children();
    return (0);
}



