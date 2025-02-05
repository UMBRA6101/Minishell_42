/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:38 by thodos-s          #+#    #+#             */
/*   Updated: 2025/02/05 17:21:32 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"
#include "../../includes/parsing_error.h"

/*	traitment of quote to add in split	*/
static int	add_quote(char *str, char *cmd, int *i_cmd, int len)
{
	bool	sq;
	bool	dq;
	int		i;

	sq = false;
	dq = false;
	i = 0;
	if (cmd[*i_cmd] == cmd[*i_cmd + 1])
	{
		(*i_cmd) += 2;
		return (0);
	}
	quote_id(&sq, &dq, i_cmd, cmd[*i_cmd]);
	while (cmd[*i_cmd] && *i_cmd < len && (sq || dq))
	{
		quote_id(&sq, &dq, NULL, cmd[*i_cmd]);
		if (!sq && !dq)
			break ;
		str[i] = cmd[(*i_cmd)];
		i++;
		(*i_cmd)++;
	}
	return (i);
}

/*	take the correct part in the buffer	*/
static char	*extract_word(int len, char *command)
{
	int		i;
	int		itr_str;
	char	*tmp;

	i = 0;
	itr_str = 0;
	tmp = ft_calloc(sizeof(char), len + 1);
	if (!tmp)
		return (NULL);
	while (command[i] && i < len)
	{
		if (command[i] == '\'' || command[i] == '\"')
			itr_str += add_quote(tmp + itr_str, command, &i, len);
		else
			tmp[itr_str++] = command[i++];
	}
	if (ft_strlen(tmp) <= 0)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

/*	add an element in split	*/
static int	add_word(t_split **split, char *elem, int *index, bool state)
{
	t_split	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (elem == NULL)
		return (0);
	tmp = ft_calloc(sizeof(t_split), (*index) + 2);
	if (!tmp)
		return (0);
	while (i < (*index))
	{
		tmp[i] = (*split)[i];
		i++;
	}
	if (*split)
		free(*split);
	(*split) = NULL;
	tmp[i].word = elem;
	tmp[i].quote = false;
	tmp[i].quote = state;
	tmp[i].len_word = ft_strlen(elem);
	(*split) = tmp;
	(*index)++;
	return (1);
}

/*	filling split with arg cut	*/
static int	fill_split(char *command, int *word_count, t_split **split)
{
	int		k;
	int		i;
	int		len_word;
	bool	state;

	k = 0;
	i = 0;
	(*word_count) = nb_words(command);
	while (command[i])
	{
		while (ft_isspace(command[i]))
			i++;
		len_word = len_of_word(command, i);
		state = b_quote(command[i]);
		add_word(split, \
			extract_word(len_word, command + i), &k, state);
		if (!(*split))
			return (0);
		i = len_word + i;
	}
	(*word_count) = k;
	free(command);
	if (*word_count <= 0)
		return (0);
	return (1);
}

/*	processing syntax command and add in struct to execution	*/
t_data_rule	*parsing(t_info *data, char **rqst)
{
	t_data_rule	*cmd;
	t_split		*split;
	int			word_count;

	cmd = NULL;
	split = NULL;
	word_count = 1;
	if (ask_tmp_files() == 1024 || ask_tmp_files() == 1025)
		data->err->exit_value = ask_tmp_files() - 894;
	if (trim_useless(rqst, data->err))
		return (NULL);
	if (!dollar_traitment(&data, rqst))
		return (0);
	data->err->error_code = STX_NL;
	if (braquet_check(*rqst, data->err) == -1)
		return (NULL);
	data->err->error_code = -1;
	if (!fill_split(*rqst, &word_count, &split)
		|| syntax_check(split, word_count, data->err))
		return (killer_split(split, word_count), NULL);
	data->err->error_code = -1;
	cmd = parsing_tree(split, word_count);
	return (cmd);
}
