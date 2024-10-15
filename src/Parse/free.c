#include "../../includes/minishell.h"

void	killer_request(t_data_rule **request)
{
	int i;
	int k;

	k = 0;
	while (k < request[k]->nb_command)
	{
		i = 0;
		while (request[k]->arguments[i] != NULL)
		{
			free(request[k]->arguments[i]);
			i++;
		}
		free(request[k]->arguments);
		k++;
	}
	free(*request);
}