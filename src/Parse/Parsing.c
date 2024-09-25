//
// Created by umbra on 9/13/24.
//
#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"

static int	fill_info(char *command, int word, t_split *split)
{
	int		k;
	int 	i;
	int 	word_len;

	k = 0;
	while (k < word)
	{
		while (ft_isspace(command[i]))
			i++;
		word_len = len_of_word(command, i);
		printf("%d\n", word_len);
		command + word_len;
	}
	return (0);
}

t_data_rule	*parsing(char *command)
{
	t_split		*split;
	int			word_count;

	split = NULL;
	command = delete_space(command);
	word_count = nb_words(command);
	split = malloc(sizeof(t_data_rule) * word_count + 1);
	if (!split || fill_info(command, word_count, split))
		return (NULL);
	return (NULL);
}

int main()
{
	printf("%d\n", nb_words("ls -a 'yo' | grep 'truc.c' > out.txt"));
}