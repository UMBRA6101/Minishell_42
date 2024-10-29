/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:22:44 by raphox            #+#    #+#             */
/*   Updated: 2024/10/29 15:30:02 by raphox           ###   ########.fr       */
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
    if (execvp(cmd[0], cmd) == -1)
    {
        perror("execvp");
        free_command(cmd);
        exit(EXIT_FAILURE);
    }
}

void first_process(t_data_rule data, char **env, int *input_fd, int *p_fd, int is_last_cmd)
{
    if (input_fd != NULL && *input_fd != -1)
    {
        dup2(*input_fd, STDIN_FILENO);
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

    if (!is_last_cmd)
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

    pid = fork();
    if (pid == -1)
    {
        exit(1);
    }
    if (pid == 0)
    {
        first_process(data, env, input_fd, p_fd, is_last_cmd);
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
        do_pipe(data[i], envp, &input_fd, (i == num_commands - 1));
        i++;
    }
    wait_for_children();
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    t_data_rule first;
    const char *tab1[3] = {"coucou", "oui et toi", NULL};
    first.command = "cat";
    first.options = NULL;
    first.arguments = NULL;
    first.nbr_args = 0;
    first.dir_path = NULL;
    first.oper = "<<";
    first.targetfile = "coucou";
    first.pipe = false;

    t_data_rule second;
    const char *tab2[3] = {"Double monstre mon coeur\n", "Triple Monstre", NULL};
    second.command = "echo";
    second.options = NULL;
    second.arguments = tab2;
    second.nbr_args = 2;
    second.dir_path = NULL;
    second.oper = ">>";
    second.targetfile = "z.txt";
    second.pipe = true;

    t_data_rule third;
    const char *tab3[2] = {"z.txt", NULL};
    third.command = "wc";
    third.options = "-l";
    third.arguments = tab3;
    third.nbr_args = 1;
    third.dir_path = NULL;
    third.oper = NULL;
    third.targetfile = NULL;
    third.pipe = true;

    t_data_rule data[1] = {first};

    return pipex(data, 1, envp);
}