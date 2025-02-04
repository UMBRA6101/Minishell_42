/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:04:30 by umbra             #+#    #+#             */
/*   Updated: 2025/01/22 21:52:20 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.h"
#include "Parsing.h"

/*	convert the redirection	*/
static	int	converte_rdir(t_data_rule *request, t_split *split)
{
	int	rdir;
	int	itr;
	int	itr_oper;

	itr = 0;
	itr_oper = 0;
	if (request->nb_rdir > 0)
		return (0);
	request->nb_rdir = ft_nb_rdir(split);
	if (request->nb_rdir <= 0)
		return (0);
	request->oper = ft_calloc(sizeof(char *), request->nb_rdir + 1);
	if (!request->oper)
		return (-1);
	while (split[itr].word != NULL
		&& (ft_strncmp(split[itr].word, "|", split[itr].len_word) != 0
			&& ft_strncmp(split[itr].word, ";", split[itr].len_word) != 0))
	{
		rdir = check_rdir(split[itr].word, split[itr].len_word);
		if (rdir != OTHER && rdir != PIPE)
			fill_conv_rdir(request, rdir, itr_oper++);
		itr++;
	}
	return (request->nb_rdir);
}

/*	add command and opition	*/
static int	init_rqst(t_data_rule *rqst, t_split *split, \
		int k, const int nb_node)
{
	int i;

	i = 0;
	if (nb_node <= 0)
		return (-1);
	rqst[k].nbr_args = 0;
	rqst[k].nb_rdir = 0;
	i += add_command(&rqst[k], split);
	if (ft_strncmp(rqst[k].command, "exit", ft_strlen(rqst[k].command)) == 0)
		return (1);
	if (echo_test(rqst + k, split, nb_node))
		return (1);
	rqst[k].nb_opt = ft_nbr_option(split + 1, nb_node);
	if (rqst[k].nb_opt == -1)
		return (-1);
	if (rqst[k].nb_opt)
		if (add_opt_request(&rqst[k], split + 1, rqst[k].nb_opt) == -1)
			return (-1);
	rqst[k].pipe = false;
	return (i + rqst[k].nb_opt);
}

/**/
static int	fill_rqst(t_split *split, t_data_rule *rqst, \
				int count_word, int k)
{
	int	nb_node;
	int	c_node;

	if (count_word <= 0)
		return (0);
	nb_node = r_node(split, 0);
	c_node = init_rqst(rqst, split, k, nb_node);
	if (c_node == -1)
		return (-1);
	while (nb_node > c_node)
	{
		if (nb_node > c_node)
			c_node += add_arg_request((rqst + k), \
			split + c_node, nb_node);
		if (c_node < nb_node \
				&& converte_rdir(&rqst[k], &split[c_node]))
			c_node += add_rdir(&rqst[k], split + c_node);
		if (c_node < count_word)
			c_node += add_pipe(&rqst[k], \
				split + c_node, count_word);
		if (c_node < count_word)
			c_node += add_semicolon(split + c_node);
	}
	return (fill_rqst(split + c_node, rqst, count_word - c_node, k + 1));
}

t_data_rule	*parsing_tree(t_split *split, const int count_word)
{
	t_data_rule	*out;

	out = ft_calloc(sizeof(t_data_rule), nb_command(split, count_word));
	if (!out)
		return (NULL);
	out->nb_command = nb_command(split, count_word);
	if (fill_rqst(split, out, count_word, 0) == -1)
	{
		free(out);
		return (NULL);
	}
	killer_split(split, count_word);
	return (out);
}
