/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:41:26 by thodos-s          #+#    #+#             */
/*   Updated: 2025/02/05 10:34:35 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"

/*	verification of validity quote	*/
static int	quote_check(char *word, t_erreur *err, int i, const int nb_word)
{
	err->c = word[0];
	if ((ft_strlen(word) <= 2))
	{
		if (check_rdir(word, ft_strlen(word)) == D_INPUT && i == 0 && nb_word > 1)
			return (0);
		if (err->sw)
		{
			err->error_code = SYNTAX;
			if (ft_strlen(word) == 2)
				err->error_code = D_SYNTAX;
			return (-1);
		}
		else if ((i == 0) || (i + 1) == nb_word)
		{
			err->error_code = STX_NL;
		}
	}
	else if (occ_rdir(word) >= 2)
	{
		err->error_code = D_SYNTAX;
		err->exit_value = 2;
		write_temp_file(TMP_FILES, err->exit_value);
		return (-1);
	}
	return (0);
}

/*	verification of validity braquet	*/
int	braquet_check(char *str, t_erreur *err)
{
	int	b_left;
	int	b_right;

	b_left = 0;
	b_right = 0;
	err->error_code = SYNTAX;
	err->c = ')';
	if (valid_braquet(str, &b_left, &b_right) == -1)
		return (-1);
	if (b_left != b_right)
	{
		err->exit_value = 2;
		write_temp_file(TMP_FILES, err->exit_value);
		return (-1);
	}
	return (0);
}

/*	verification of validity operator	*/
static int	oper_check(t_erreur *err, const char *word, \
		const int i, const int nb_word)
{
	int	occ;

	occ = 0;
	err->c = word[0];
	err->error_code = SYNTAX;
	if (err->sw)
		return (-1);
	while (word[occ] == err->c)
		occ++;
	if (occ >= 2)
	{
		err->error_code = D_SYNTAX;
		return (-1);
	}
	if ((err->sw) || i == 0 || (nb_word - 1) == i)
		return (-1);
	return (0);
}

static int	valid_stx(t_split *split, int i, t_erreur *err, const int nb_word)
{
	if (split[i].sep == '|' || split[i].sep == ';' || split[i].sep == '&')
	{
		if (oper_check(err, split[i].word, i, nb_word) == -1)
			return (-1);
	}
	else if ((!previous_pipe(split, i) && (i == 0 || i + 1 == nb_word))
		&& (split[i].sep == '>' || split[i].sep == '<'))
		if (quote_check(split[i].word, err, i, nb_word) == -1)
			return (-1);
	return (0);
}

/*	verification syntax*/
int	syntax_check(t_split *split, const int nb_word, t_erreur *err)
{
	int			i;

	i = 0;
	err->sw = 0;
	if (!split || split->word == NULL)
		return (0);
	while (i < nb_word)
	{
		split[i].sep = split[i].word[0];
		if ((split[i].sep == '|' || split[i].sep == ';' || split[i].sep == '<'
				|| split[i].sep == '>'
				|| split[i].sep == '&') && !(split[i].quote))
		{
			if (valid_stx(split, i, err, nb_word) == -1)
				return (-1);
			err->sw = 1;
		}
		else
			err->sw = 0;
		i++;
	}
	if (err->error_code == STX_NL)
		return (-1);
	return (0);
}
