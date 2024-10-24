#include "pipex_bonus.h"

//------------------------------------------------------------------------------


// Function Prototypes
#include "pipex_bonus.h"
# include "libft/libft.h"

#include "pipex_bonus.h"


//------------------------------------------------------------------------------


#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


void execute(t_data_rule data, char **envp)
{
    char **cmd = build_command(data);

    if (!cmd[0])
    {
        error(1, NULL);
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
    if (!is_last_cmd) // n est pas la derniere commande
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

    if (!is_last_cmd) // n est pas la derniere commande
    {
        close(p_fd[1]);
        *input_fd = p_fd[0]; // redirige l’entrée pour la prochaine commande dans le pipeline.
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

// int main(int argc, char **argv, char **envp)
// {
//     t_data_rule first;
//     const char *tab3[3] = {"bonjour comment ca va", "oui et toi", NULL};
//     first.command = "echo";
//     first.options = NULL;
//     first.arguments = tab3;
//     first.nbr_args = 2;
//     first.dir_path = NULL;
//     first.out = NULL;
//     first.pipe = true;

//     t_data_rule second;
//     const char *tab2[2] = {"double.txt", NULL};
//     second.command = "cat";
//     second.options = NULL;
//     second.arguments = tab2;
//     second.nbr_args = 1;
//     second.dir_path = NULL;
//     second.out = NULL;
//     second.pipe = false;

//     t_data_rule third;
//     const char *tab1[3] = {"w", "NULL", NULL};
//     third.command = "grep";
//     third.options = NULL;
//     third.arguments = tab1;
//     third.nbr_args = 1;
//     third.dir_path = NULL;
//     third.out = NULL;
//     third.pipe = false;

//     t_data_rule data[3] = {first, second, third};

//     return pipex(data, 3, envp);
// }

