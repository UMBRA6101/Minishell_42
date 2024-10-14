#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{

	// char	*rule;
	// t_data_rule *request;

	// rule = NULL;

	// char **env;
	// env = envp;

//---------------------------------
	t_data_rule first;

	const char *tab[4];
	tab[0] = "NULL";
	tab[1] = "NULL";
	tab[2] = "UNLL";
	tab[3] = NULL;

	// const char **tab;
	// *tab = NULL;

	first.command = "unset";
	first.options = NULL;
	first.arguments = NULL;
// -----------------------------------------
	printf("FIRST ENV ----------------------------------------------------------------------------\n");
	display_env(envp);
	exec_builtins(first, envp);
	// display_env(envp);
	return (0);

//---------------------------------


	// rule = readline(PROMPT);
	// if (rule != NULL)
	// {
	// 	// request = parsing(rule);
	// 	exec_builtins(first, genv);
	// 	(void)request;
	// }
	return (0);
}
