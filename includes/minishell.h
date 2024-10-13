#ifndef MINISHELL_H
# define MINISHELL_H


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
# include "libft.h"
# include "stdbool.h"
# include "Parsing.h"

# define PROMPT "Minishell-> "


// extern int genvu;

typedef struct 	s_data_rule
{
	// char	**envv;
	char	*command;
	char *options;
	const char 		**arguments;
	int 	nbr_args;
	char	*dir_path;
	char	*out;
	char 	oper; // r = >>
	bool 	pipe;
}				t_data_rule;

// MAIN.C ------------------------------------------------------------------------------------------
char			*lexing(char *brut_rules); // transformation de commande en token
t_data_rule		*parsing(char *command); // verification du token et decoupage dans la structure

// BUILTINS.C --------------------------------------------------------------------------------------
void exec_builtins(t_data_rule struc, char **genv);

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

//TOOLS.C ------------------------------------------------------------------------------------------

void swap(char **a, char **b);
int	find_in_envv(char **envv, char *var);
void	bubble_sort(char **envp);
void display_x_variables(char **result);
int compare_strings(const char *str1, const char *str2);

//ERROR.C ------------------------------------------------------------------------------------------
void free_env(char **env);



#endif
