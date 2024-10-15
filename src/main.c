#include "minishell.h"

int	main(void)
{
	char	*rule;
	t_erreur	err;
	t_data_rule *request;

	err.error_code = -1;
	while (1)
	{
		rule = NULL;
		rule = readline(PROMPT);
		if (rule != NULL) {
			request = parsing(rule, &err);
			if (!request)
				print_parsing_error(err);
			(void) request;
			killer_request(&request);
			free(rule);
		}
	}
	return 0;
}
