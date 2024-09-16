#ifndef MINISHELL_H
# define MINISHELL_H


# include "../pipex/pipex.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
#include <sys/wait.h>

# define PROMPT "Minishell-> "

typedef struct 	s_data_rule
{
	char	*dir_path;
	char	**argument;
	char	*out;
	char	*in;
}				t_data_rule;

// Main.c
char			*lexing(char *brut_rules); // transformation de commande en token
t_data_rule		parsing(char *token); // verification du token et decoupage dans la structure 

#endif