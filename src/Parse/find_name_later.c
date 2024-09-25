#include "Parsing.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 10 && c <= 13))
		return (1);
	return (0);
}

int	is_oper(char c)
{
	if (c == '=' || c == '|' || c == ';' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_isend(const char c)
{
	if (ft_isspace(c) || c == '\'' || c == '\"')
		return (1);
	return (0);
}

char	*delete_space(char *command)
{
	int	i;

	i = ft_strlen(command) - 1;
	while (i > 0 && ft_isspace(command[i]))
	{
		command[i] = '\0';
		i--;
	}
	return (command);
}

int	state_finish(t_token *token)
{
	if (token->state != OPER || token->sep == '=' || token->sep == ';')
		return (token->nb_word);
	return (-1);
}

int	nb_words(char *command)
{
	t_token token;

	token.len_word = -1;
	token.nb_word = 0;
	token.state = RESET;
	token.sep = ' ';
	return (r_value(command, 0, &token));
}

int	len_of_word(char *command, int i)
{
	t_token	token;

	token.len_word = 0;
	token.nb_word = 0;
	token.state = RESET;
	token.sep = ' ';
	return (r_value(command, i, &token));
}