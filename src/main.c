#include "minishell.h"

int	main(void)
{
	char	*rule;
	t_data_rule *request;

	rule = NULL;
	rule = readline(PROMPT);
	if (rule != NULL)
	{
		request = parsing(rule);
		(void)request;
	}
	return (0);
}
