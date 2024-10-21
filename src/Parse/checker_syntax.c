#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"

static int	occ_quote(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] == '>' || buff[i] == '<')
		i++;
	return (i);
}

static int	quote_check(char *word, t_erreur *err, int i, const int nb_word)
{
	if ((ft_strlen(word) <= 2) || (((i + 1) == nb_word) && i != 0))
	{
		if ((i == 0) || (word[0] == word[1]))
			err->error_code = SYNTAX;
		if ((i + 1) == nb_word)
			err->error_code = STX_QUOTE;
		return (-1);
	}
	else if (occ_quote(word) >= 2)
	{
		err->c = word[0];
		err->error_code = D_SYNTAX;
		return (-1);
	}
	return (0);
}

int	syntax_check(t_split *split, const int nb_word, t_erreur *err)
{
	int	i;
	int	sw;
	char sep;

	i = 0;
	sw = 0;
	while (i < nb_word)
	{
		sep = split[i].word[0];
		if (sep == '|' || sep == ';' || sep == '<' || sep == '>')
		{
			if (sw || ((sep == '|' || sep == ';') && i == 0))
			{
				err->c = sep;
				return (-1);
			}
			else if (sep == '>' || sep == '<')
			{
				if (quote_check(split[i].word, err, i, nb_word) == -1)
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