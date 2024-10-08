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

typedef struct 	s_data_rule
{
	char	**envv;
	char	*command;
	char *options;
	const char 		**arguments;
	char	*dir_path;
	char	*out;
	char 	oper; // r = >>
	bool 	pipe;
}				t_data_rule;

// Main.c
char			*lexing(char *brut_rules); // transformation de commande en token
t_data_rule		*parsing(char *command); // verification du token et decoupage dans la structure

// Builtins
void exec_builtins(t_data_rule struc);
int	find_in_envv(char **envv, char *var);

void cd(char *command, char **arguments, char **envp); // recopie cd // good
void echo(char *command, char *option, const char **arguments); // recopie echo 2 ou + arg // good
void display_env(char **envp); // Affiche l env fonction : env

static char  **copy_env(char **envp); // copy l env

void export(char *command, char **arguments, char **env); // ajouter variable a l env 2 ou+ 
void pwd(char *command, char **envv); // recopie pwd
void	unset_var(char **env, const char *var);  // retirer variable de l env


//test
void malloc_struc();



#endif
