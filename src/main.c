#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{

	char	*rule;
	t_data_rule *request;
	rule = NULL;

	// const char **tab;
	// *tab = NULL;
	const char *tab[2];
	tab[0] = "MY_VAR=LA BONNE VARIABLE";
	tab[1] = "comment";
	tab[2] = 0;
	
	t_data_rule first;
	first.envv = envp;
	first.command = "unset";
	first.options = NULL;
	first.arguments = tab;


	exec_builtins(first);
	return (0);



	rule = readline(PROMPT);
	if (rule != NULL)
	{
		// request = parsing(rule);
		exec_builtins(first);
		(void)request;
	}
	return (0);
}
