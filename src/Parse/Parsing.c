//
// Created by umbra on 9/13/24.
//
#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"

static void free_split(t_split *split)
{
	t_split *temp;

	temp = split;
	if (!split)
		return ;
	free(split->word);
	split++;
	if (temp)
		free(temp);
}

void add_word(t_split *word, char *command, int word_len)
{
	ft_strlcpy(word->word, command, word_len + 1);
	word->word[word_len + 1] = '\0';
}

static int	fill_info(char *command, int word, t_split *split)
{
	int		k;
	int 	i;

	k = 0;
	i = 0;
	while (k < word)
	{
		while (ft_isspace(command[i]))
			i++;
		split[k].len_word = len_of_word(command, i);
		split[k].word = ft_calloc(sizeof(char), (split[k].len_word + 2));
		add_word(&split[k], command + i , split[k].len_word);
		i = split[k].len_word + i;
		k++;
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
	split = ft_calloc(sizeof(t_split), (word_count + 1));
	if (!split || (fill_info(command, word_count, split) < 0))
		return (NULL);
	parsing_tree(split, word_count);
	free_split(split);
	return (NULL);
}