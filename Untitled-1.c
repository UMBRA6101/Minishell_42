/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:22:44 by raphox            #+#    #+#             */
/*   Updated: 2024/11/05 19:01:35 by raphox           ###   ########.fr       */
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

    if (!is_last_cmd) // pas la derniere commande
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



int main(int argc, char **argv, char **envp)
{

	char	*rule;
	(void)argc;
	(void)argv;

	char **envv;
	envv = envp;

	t_data_rule first;
    const char *tab1[3] = {"Double monstre mon coeur", "Triple Monstre", NULL};
    first.command = "env";
    first.options = NULL;
    first.arguments = NULL;
    first.nbr_args = 0;
    first.dir_path = NULL;
    first.oper = ">>";
    first.targetfile = "z.txt";
    first.pipe = true;

    t_data_rule second;
    const char *tab2[2] = {"VAR4=AAAAAAAAAAAAAAAAAHHHHhhhhhhhhhhhhhhhhhhh", NULL};
    second.command = "export";
    second.options = NULL;
    second.arguments = tab2;
    second.nbr_args = 1;
    second.dir_path = NULL;
    second.oper = ">>";
    second.targetfile = "z.txt";
    second.pipe = true;

    t_data_rule third;
    third.command = "env";
    third.options = NULL;
    third.arguments = NULL;
    third.nbr_args = 0;
    third.dir_path = NULL;
    third.oper = ">>";
    third.targetfile = "z.txt";
    third.pipe = true;

	// char **envv;
    // char *tableau[4] = {"coucou", "ca va la famille\n", "ouai la forme la forme\n", NULL};
	// envv = tableau;
	
    // t_data_rule data[1] = {first};
    // t_data_rule data2[1] = {second};
    // t_data_rule data3[1] = {third};
	
    // t_data_rule data[2] = {first, second};
    t_data_rule data[3] = {first, second, third};

	while (1)
	{
		rule = NULL;
		rule = readline("minishell->");
		if (rule != NULL) 
		{
			// pipex(data, 1, envv);
			// pipex(data2, 1, envv);
			// pipex(data3, 1, envv);
			// pipex(data, 2, envp);
			pipex(data, 3, envv);
		}
	}
	// display_env(envp);
	return 0;


int exec_builtins(t_data_rule struc, char **envp)
{	
	if (ft_strncmp(struc.command, "cd", ft_strlen(struc.command)) == 0)
	{
		cd(struc.command, struc.arguments, envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "echo", ft_strlen(struc.command)) == 0)
	{
		echo(struc.command, struc.options, struc.arguments);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "env", ft_strlen(struc.command)) == 0)
	{
		display_env(envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "export", ft_strlen(struc.command)) == 0)
	{	
		envp = export(struc.command, struc.arguments, envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "pwd", ft_strlen(struc.command)) == 0)
	{
		pwd(struc.command, envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "unset", ft_strlen(struc.command)) == 0)
	{
			envp = unset(struc.command, struc.arguments, envp);
			// printf("RESULT ENV ----------------------------------------------------------------------------\n\n\n");
			// display_env(envp);
			exit(EXIT_SUCCESS);

	}
	return (0);
}


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
        fd = open(data.targetfile, O_WRONLY | O_CREAT | O_APPEND, 0777);
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


// ------------------------------------------------------------------------------------------------------
char	**export(char *command, const char **arguments, char **envv)
{
	int		i;
	char	**result;
	char	**new_result;

	i = 0;
	result = envv;
	if (command != NULL && arguments == NULL)
	{
		bubble_sort(result);
		display_x_variables(result);
	}
	else
	{
		while (arguments[i] != NULL)
		{
			new_result = cmd_export(command, arguments[i++], result);
			// if (new_result != result && result != env)
			// 	free_env(result);
			result = new_result;
		}
		// i = 0;
	}
	// if (result != env)
		// free_env(result);
	// display_x_variables(result);
	return (result);
}



char	**cmd_export(char *command, const char *argument, char **env)
{
	int check;
	char	**new_env;
	int		size;

	check = 0;
	if (command == NULL || argument == NULL)
		return (env);
	new_env = allocate_new_env_to_add_variable(env);
	if (!new_env)
		exit(EXIT_FAILURE);
	size = size_env(env, new_env);
	
	while (env[check] != NULL)
	{
		if (ft_strncmp(env[check], argument, ft_strlen(env[check])) == 0)
			return (env);
		check++;
	}

	
	if (size == -1)
		exit(EXIT_FAILURE);
	new_env[size] = strdup(argument);
	if (!new_env[size])
	{
		free_env(new_env);
		exit(EXIT_FAILURE);
	}
	new_env[size + 1] = NULL;
	return (new_env);
}

// allouer nouvel environnement
char	**allocate_new_env_to_add_variable(char **env)
{
	int		size;
	char	**new_env;

	size = 0;
	while (env[size])
		size++;
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
		return (NULL);
	return (new_env);
}

int		size_env(char **env, char **new_env)
{
	int		j;

	j = 0;
	while (env[j] != NULL)
	{
		new_env[j] = strdup(env[j]);
		if (!new_env[j])
		{
			free_env(new_env);
			return (-1);
		}
		j++;
	}
	return (j);
}