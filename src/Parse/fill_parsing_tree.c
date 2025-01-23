/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parsing_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:25:52 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/22 21:50:24 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/Parsing.h"

/*	add other command	*/
int	add_semicolon(t_split *split)
{
	if (split->word && ft_strncmp(split->word, ";", split->len_word) == 0)
	{
		return (1);
	}
	return (0);
}

/*	fuck the norm	*/
static void	add_previous_arg(t_data_rule **rqst, char **tmp)
{
	int	i;

	i = 0;
	while (i < (*rqst)->nbr_args)
	{
		tmp[i] = (*rqst)->arguments[i];
		i++;
	}
	free((*rqst)->arguments);
}

/*	add executable argument	*/
int	add_arg_request(t_data_rule *request, t_split *split, const int nb_node)
{
	int		itr_arg;
	int		i;
	char	**temp;

	itr_arg = 0;
	i = 0;
	if (!split)
		return (0);
	while (itr_arg < nb_node && ft_strncmp(split[itr_arg].word, ";", \
		split[itr_arg].len_word) != 0 && check_rdir(split[itr_arg].word, \
		split[itr_arg].len_word) == OTHER && split[itr_arg].word != NULL)
		itr_arg++;
	if (itr_arg <= 0)
		return (0);
	temp = ft_calloc(sizeof(char *), itr_arg + request->nbr_args + 1);
	add_previous_arg(&request, temp);
	i = 0;
	while (i < itr_arg)
	{
		temp[i + request->nbr_args] = ft_strdup(split[i].word);
		i++;
	}
	request->arguments = temp;
	request->nbr_args += itr_arg;
	return (itr_arg);
}

/*	add redirection and arg path redirection in struct	*/
int	add_rdir(t_data_rule *request, t_split *split)
{
	int	rdir;
	int	itr_oper;
	int	itr;

	itr_oper = 0;
	itr = 0;
	if (!split)
		return (0);
	request->out = ft_calloc(sizeof(char *), request->nb_rdir + 1);
	if (!request->out)
		return (0);
	while (split[itr].word != NULL && itr_oper < request->nb_rdir \
		&& (ft_strncmp(split[itr].word, ";", split[itr].len_word) != 0))
	{
		rdir = check_rdir(split[itr].word, split[itr].len_word);
		if (rdir == PIPE)
			return (itr);
		if (rdir != OTHER)
			fill_rdir(request, split, itr++, itr_oper++);
		itr++;
	}
	return (itr);
}
