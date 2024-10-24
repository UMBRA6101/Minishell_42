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

void wait_for_children(void)
{
    int status;

    while (wait(&status) > 0)
    {
        // Waiting for all child processes
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

void free_command(char **cmd)
{
    int i = 0;
    if (!cmd)
    {
        return;
    }
    while (cmd[i])
    {
        free(cmd[i]);
        i++;
    }
    free(cmd);
}

// char **build_command(t_data_rule data)
// {
//     int i = 0;
//     int j = 0;
//     char **cmd;
//     char **split_command = NULL;

//     if (data.options)
//     {
//         split_command = ft_split(data.options, ' ');
//         while (split_command && split_command[j])
//         {
//             j++;
//         }
//     }

//     cmd = malloc((j + data.nbr_args + 2) * sizeof(char *));
//     if (!cmd)
//     {
//         if (split_command)
//         {
//             free_command(split_command);
//         }
//         exit(1);
//     }

//     cmd[i] = strdup(data.command);
//     if (!cmd[i])
//     {
//         if (split_command)
//         {
//             free_command(split_command);
//         }
//         free_command(cmd);
//         exit(1);
//     }
//     i++;

//     int k = 0;
//     while (k < j)
//     {
//         cmd[i] = strdup(split_command[k]);
//         if (!cmd[i])
//         {
//             if (split_command)
//             {
//                 free_command(split_command);
//             }
//             free_command(cmd);
//         	exit(1);
            
//         }
//         i++;
//         k++;
//     }

//     if (split_command)
//     {
//         free(split_command);
//     }

//     k = 0;
//     while (k < data.nbr_args)
//     {
//         cmd[i] = strdup(data.arguments[k]);
//         if (!cmd[i])
//         {
//             free_command(cmd);
//         	exit(1);
            
//         }
//         i++;
//         k++;
//     }

//     cmd[i] = NULL;
//     return cmd;
// }

void first_process(t_data_rule data, char **env, int *input_fd, int *p_fd, int is_last_cmd)
{
    if (input_fd != NULL && *input_fd != -1)
    {
        dup2(*input_fd, STDIN_FILENO);
        close(*input_fd);
    }
    if (is_last_cmd != 0) // n est pas la derniere commande
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

    if (is_last_cmd != 0) // n est pas la derniere commande
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

int main(int argc, char **argv, char **envp)
{
    t_data_rule first;
    const char *tab3[3] = {"bonjour comment ca va", "oui et toi", NULL};
    first.command = "echo";
    first.options = NULL;
    first.arguments = tab3;
    first.nbr_args = 2;
    first.dir_path = NULL;
    first.out = NULL;
    first.pipe = true;

    t_data_rule second;
    const char *tab2[2] = {"double.txt", NULL};
    second.command = "cat";
    second.options = NULL;
    second.arguments = tab2;
    second.nbr_args = 1;
    second.dir_path = NULL;
    second.out = NULL;
    second.pipe = false;

    t_data_rule third;
    const char *tab1[3] = {"w", "NULL", NULL};
    third.command = "grep";
    third.options = NULL;
    third.arguments = tab1;
    third.nbr_args = 1;
    third.dir_path = NULL;
    third.out = NULL;
    third.pipe = false;

    t_data_rule data[3] = {first, second, third};

    return pipex(data, 3, envp);
}

