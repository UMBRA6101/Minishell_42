#include "minishell.h"

int	main(void)
{
	char	*rule;
	char	*lex;

	rule = NULL;
	rule = readline(PROMPT);
	
	if (rule != NULL)
	{
		lex = lexing(rule);
	}

	return (0);
}