/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:45:57 by raphox            #+#    #+#             */
/*   Updated: 2024/10/14 18:06:36 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


//------------------------------------------------------------------------------


int open_file(char *file, int in_or_out)
{
    int ret;

    if (in_or_out == 0)
        ret = open(file, O_RDONLY, 0777);
    if (in_or_out == 1)
        ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (in_or_out == 2)
        ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (ret == -1)
        exit(0);
    return (ret);
}

void do_pipe(char *cmd, char **env)
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
        close(p_fd[0]);
        dup2(p_fd[1], STDOUT_FILENO);
        execute(cmd, env);
    }
    else
    {
        close(p_fd[1]);
        dup2(p_fd[0], 0);
    }
}

int main(int ac, char **av, char **envp)
{
    int index;
    int fd_in;
    int fd_out;
    pid_t pid;
    int status;

    if (ac < 5)
    {
        write(2, "Usage: ./pipex infile cmd1 cmd2 ... cmdn outfile\n", 49);
        return (1);
    }

    index = 2;
    fd_in = open_file(av[1], 0);
    fd_out = open_file(av[ac - 1], 1);
    dup2(fd_in, STDIN_FILENO);

    while (index < ac - 2)
    {
        do_pipe(av[index], envp);
        index++;
    }
    pid = fork();
    if (pid == -1)
        exit(0);
    if (pid == 0)
    {
        dup2(fd_out, STDOUT_FILENO);
        execute(av[ac - 2], envp);
    }

    close(fd_in);
    close(fd_out);

    // Wait for all child processes to finish
    while (wait(&status) > 0);

    return (0);
}
