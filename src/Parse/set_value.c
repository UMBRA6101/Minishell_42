/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:37:39 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/22 12:13:11 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.h"

/*	count len of quote elem('...', "...")	*/
static int	is_quote(bool *sq, bool *dq, char *command)
{
	int	k;

	k = 1;
	while (command[k] && (*sq || *dq))
	{
		quote_id(sq, dq, NULL, command[k]);
		k++;
	}
	return (k);
}

/*	count of redirection elem(<, >)	*/
static int	is_rrdir(char *command, int i, t_token *token)
{
	int	k;

	k = i;
	while (command[i] && is_rdir(command[i]))
		i++;
	if (token->len_word == 0)
		token->len_word = i - k;
	return (r_value(command, i, token));
}

/*	count len of and operator element(|, ;)	*/
static int	is_r_oper(char *command, int i, t_token *token)
{
	int	k;

	k = i;
	while (command[i] && is_oper(command[i]))
		i++;
	if (token->len_word == 0)
		token->len_word = i - k;
	return (r_value(command, i, token));
}

/*	count len of space element	*/
static int	is_space(char *command, int i, t_token *token)
{
	int		k;
	bool	sq;
	bool	dq;

	k = i;
	sq = false;
	dq = false;
	while (command[i] && !ft_isend(command[i]))
	{
		quote_id(&sq, &dq, NULL, command[i]);
		if (sq || dq)
			i += is_quote(&sq, &dq, command + i);
		else
			i++;
	}
	if (token->len_word == 0)
		token->len_word = i - k;
	return (r_value(command, i, token));
}

/*	count word or len of the word	*/
int	r_value(char *command, int i, t_token *token)
{
	int	l;

	l = ft_strlen(command);
	if (token->len_word > 0)
		return (token->len_word);
	if (i >= l)
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
	else if (token->state == RDIR)
		return (is_rrdir(command, i, token));
	else
		return (is_r_oper(command, i, token));
}
