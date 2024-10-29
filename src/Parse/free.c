#include "minishell.h"
#include "Parsing.h"

void	killer_request(t_data_rule **request)
{
	int i;
	int k;
	int	nb_arg;
	int	nb_com;

	i = 0;
	k = 0;
	if (!(request[k]))
		return ;
	nb_com = request[k]->nb_command;
	while (k < nb_com)
	{
		nb_arg = request[k]->nbr_args;
		printf("nb_arg = %d\n", nb_arg);
		while (i < nb_arg)
		{
			free(request[k]->arguments[i]);
			i++;
		}
		k++;
	}
	free(*request);
}