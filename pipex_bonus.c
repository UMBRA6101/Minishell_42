/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:22:44 by raphox            #+#    #+#             */
/*   Updated: 2024/10/29 15:26:30 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include<stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include "stdbool.h"

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