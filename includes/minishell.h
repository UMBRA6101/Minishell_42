#ifndef MINISHELL_H
# define MINISHELL_H


# include "../pipex/pipex.h"

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

# define PROMPT "Minishell-> "

typedef struct 	s_data_rule
{
	char	**env;
	const char	*command;
	const char *options;
	const 		**arguments;
	char	*dir_path;
	char	*out;
	char 	*oper;
}				t_data_rule;

// Main.c
char			*lexing(char *brut_rules); // transformation de commande en token
t_data_rule		parsing(char *token); // verification du token et decoupage dans la structure

// Builtins
void cd(char *command, char **arguments, char **envp); // recopie cd // good
void echo(char *command, char *option, char **arguments); // recopie echo 2 ou + arg // good
void display_env(char **envp); // Affiche l env fonction : env
static char  **copy_env(char **envp); // copy l env
void export(char *command, char **arguments, char **env); // ajouter variable a l env 2 ou+ 
void pwd(char *command, char **arguments, char **envp); // recopie pwd
void	unset_var(char **env, const char *var);  // retirer variable de l env





#endif