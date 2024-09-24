//
// Created by umbra on 9/13/24.
//
#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"

t_data_rule	*parsing(char *command)
{
	int	words;

	command = delete_space(command);
	words = nb_words(command);
	(void)words;
	// ajouter les info
	return (NULL);
}

int main()
{
	printf("%d\n", nb_words("ls -a 'yo'"));
}