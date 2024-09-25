//
// Created by umbra on 9/23/24.
//
#include "Parsing.h"

static int	is_d_quote(char *command, int i, t_token *token)
{
	while (command[i] && command[i] == '\"')
		i++;
	while (command[i] && !ft_isend(command[i]))
		i++;
	return (r_value(command, i, token));
}

static int	is_quote(char *command, int i, t_token *token)
{
	while (command[i] && command[i] != '\'')
	{
		i++;
		printf("%c", command[i]);
	}
	printf("\n");
	while (command[i] && !ft_isend(command[i]))
		i++;
	return (r_value(command, i, token));
}

static int	is_space(char *command, int i, t_token *token)
{
	while (command[i] && !ft_isend(command[i]))
		i++;
	if (token->len_word == 0)
		token->len_word = i;
	return (r_value(command, i, token));
}

int	r_value(char *command, int i, t_token *token)
{
	int	l;

	l = ft_strlen(command);
	if (i >= l)
		return (state_finish(token));
	if (token->len_word > 0)
		return (state_finish(token));
	while (ft_isspace(command[i]))
		i++;
	if (command[i] == '\0')
		return (state_finish(token));
	token->sep = command[i];
	token->state = state_in_view(command, i);
	(token->nb_word)++;
	if (token->state == SPACES)
		return (is_space(command, i, token));
	else if (token->state == QUOTE)
		return (is_quote(command, i + 1, token));
	else if (token->state == D_QUOTE)
		return (is_d_quote(command, i + 1, token));
	return (0);
}