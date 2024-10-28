#include "minishell.h"
#include "Parsing.h"

void	killer_request(t_data_rule **request)
{
	int i;
	int k;

	k = 0;
	printf("nb_word : %d\n", request[k]->nbr_args);
	if (!(request[k]))
		return ;
	if (request[k]->arguments)
	{
		while (k < request[k]->nb_command) {
			i = 0;
			free(request[k]->command);
			while (i < request[k]->nbr_args) {
				free(request[k]->arguments[i]);
				i++;
			}
			free(request[k]->arguments);
			k++;
		}
	}
	free(*request);
}
