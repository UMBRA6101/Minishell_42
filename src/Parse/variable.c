#include "../../includes/Parsing.h"

int find_var(char *command)
{
	int	i;
	int count_var;

	i = 0;
	count_var = 0;
	while (command[i])
	{
		if (command[i] == '=')
			count_var++;
		i++;
	}
	return (count_var);
}

int add_var(t_variable *var, char *command, int len)
{
	int i;

	i = 0;
	printf("%s\n", command);
	while(i < len && command[i] != '=')
		i++;
	if (!command[i])
		return (-1);
	i++;
	var->name = ft_strtok(command, "=");
	var->value = ft_strtok(command + i, " ");
	return (0);
}

int fill_var(t_split *split, char *command, t_variable *var)
{
	int	i;
	int k;

	i = 0;
	while (i < split->len_word && command[i] != '$')
		i++;
	if (ft_strncmp(command + i, var[k].name) == 0)
		split->word
}