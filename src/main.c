#include "minishell.h"
int	main(void)
{
	char	*rule;

	rule = NULL;
	rule = readline(PROMPT);
	if (rule != NULL)
	{
		//lex = lexing(rule);
		//printf("%s\n", lex);
	}
	return (0);
}
