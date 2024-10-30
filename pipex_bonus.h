/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:10:50 by raphox            #+#    #+#             */
/*   Updated: 2024/10/30 16:11:36 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# include <fcntl.h>
# include <string.h>
# include "stdbool.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_data_rule
{
    char *command;
    char *options;
    const char **arguments;
	char *targetfile;
    int nbr_args;
    char *dir_path;
	char *oper;
    bool pipe;

} t_data_rule;


// PIPEX BONUS . C ---------------------------------------------------------------------------------------------

int pipex(t_data_rule *data, int num_commands, char **envp);


void wait_for_children(void);
void execute(t_data_rule data, char **envp);
void free_command(char **cmd);
void first_process(t_data_rule data, char **env, int *input_fd, int *p_fd, int is_last_cmd);
void second_process(int *input_fd, int *p_fd, int is_last_cmd);
void do_pipe(t_data_rule data, char **env, int *input_fd, int is_last_cmd);
void exit_with_error(const char *msg);


// BUILD COMMAND . C ---------------------------------------------------------------------------------------------

char    **build_command(t_data_rule data);
int    count_options(char *options, char ***split_command);
char    **allocate_command(int options_count, int nbr_args);
int    copy_command_to_cmd(char **cmd, char *command);
int    copy_options_to_cmd(char **cmd, char **split_command, int *i, int j);
int    copy_arguments_to_cmd(char **cmd, const char **arguments, int *i, int nbr_args);

// TOOLS . C ---------------------------------------------------------------------------------------------

void error(int i, char *str);
void    free_command(char **cmd);
void wait_for_children(void);
void handle_heredoc(const char *delimiter);
void handle_redirection(t_data_rule data);


// SPLIT . C ---------------------------------------------------------------------------------------------

char	**ft_split(char *s, char c);



// BUILTINS . C ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int exec_builtins(t_data_rule struc, char **envp);

//Echo
void cd(char *command, const char **arguments, char **envp);

//Echo
void echo(char *command, char *option, const char **arguments);
void display_echo(char *command, char *option, const char **arguments, char *result);

//Env
void display_env(char **envp); // env

//Export
char **export(char *command, const char **arguments, char **env);
char **cmd_export(char *command, const char *arguments, char **env); // ajouter variable a l env 2 ou+ 
char	**allocate_new_env(char **env);
int		copy_env(char **env, char **new_env);

//Pwd
void pwd(char *command, char **envv); // recopie pwd

//Unset
char **unset(char *command, const char **arguments, char **envp);
char **cmd_unset(char **env, const char *var);  // retirer variable de l env


// ERROR . C
void	free_env(char **env);

//TOOLS BUILT. C ------------------------------------------------------------------------------------------

void swap(char **a, char **b);
int	find_in_envv(char **envv, char *var);
void	bubble_sort(char **envp);
void display_x_variables(char **result);
int compare_strings(const char *str1, const char *str2);


#endif