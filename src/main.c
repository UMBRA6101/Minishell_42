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

	const char *tab[5];
	tab[0] = "bonjou";
	tab[1] = "var2";
	tab[2] = "var3";
	tab[3] = "var4";
	tab[4] = NULL;

	// const char **tab;
	// *tab = NULL;

	first.command = "export";
	first.options = NULL;
	first.arguments = NULL;
// -----------------------------------------


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
