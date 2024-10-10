//
// Created by umbra on 9/13/24.
//
#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"
#include "../../includes/parsing_error.h"

void add_word(t_split *word, char *command, int word_len)
{
	ft_strlcpy(word->word, command, word_len + 1);
	word->word[word_len + 1] = '\0';
}

static int	syntax_check(t_split *split, int word, t_erreur *err)
{
	int i;
	int sw;
	char sep;

	i = 0;
	while (i < word)
	{
		
		sep = split[i].word[0];
		if (sep == '|' || sep == ';' || sep == '<' || sep == '>')
		{
			if (sw || (i == 0 && (sep == '|' || sep == ';')))
			{
				err->c = sep;
				return (-1);
			}
			sw = 1;
		}
		else
			sw = 0;
		i++;
	}
	return (0);
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
		printf("k : %d\n", k);
	}
/*	printf("word : %d\n", word);
	printf("%s\n", split[k - 1].word);*/
	if (check_rdir(split[k - 1].word, split[k - 1].len_word) == 1)
		return (-1);
	return (0);
}

t_data_rule	*parsing(char *command, t_erreur *err)
{
	t_data_rule *request;
	t_split		*split;
	int			word_count;

	split = NULL;
	command = delete_space(command);
	if (ft_strlen(command) == 0)
		return (NULL);
	word_count = nb_words(command);
	err->error_code = STX_QUOTE;
	if (word_count < 0)
		return (NULL);
	err->error_code = STX_ALLOC;
	split = ft_calloc(sizeof(t_split), (word_count + 1));
	if (!split || (fill_info(command, word_count, split) < 0))
		return (NULL);
	err->error_code = SYNTAX;
	if (syntax_check(split, word_count, err))
		return (NULL);
	request = parsing_tree(split, word_count);
	return (request);
}