/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:04:30 by umbra             #+#    #+#             */
/*   Updated: 2024/10/29 15:50:04 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by umbra on 10/1/24.
//

#include "../../includes/Parsing.h"
#include "Parsing.h"

static int	add_arg_request(t_data_rule *request, t_split  *split, int nb_node);

static int add_command(t_data_rule *request, t_split *split)
{
	if (!split)
		return (-1);
	request->command = split[0].word;
	return (0);
}

static int add_pipe(t_data_rule *request, t_split *split, int count_word)
{
	if (count_word <= 0 || !split)
		return (0);
	if (ft_strncmp(split->word, "|", split->len_word) == 0)
	{
		request->pipe = true;
		return (1);
	}
	return (0);
}

static int	converte_rdir(t_data_rule *request, t_split *split)
{
	int rdir;

	rdir = check_rdir(split->word, split->len_word);
	if (rdir != OTHER && rdir != PIPE)
	{
		if (rdir == D_RDIR)
			request->oper = 'r';
		if (rdir == RDIR)
			request->oper = '>';
		if (rdir == INPUT)
			request->oper = '<';
		return (1);
	}
	return (0);
}

static int add_out_request(t_data_rule *request, t_split *split)
{
	if (!split)
		return (0);
	request->out = split->word;
	return (1);
}

static int add_arg_request(t_data_rule *request, t_split  *split, int nb_node)
{
	int itr_arg;

	itr_arg = 0;
	if (!split)
		return (-1);
	while (itr_arg < nb_node)
	{
		request->arguments[itr_arg] = split[itr_arg].word;
		itr_arg++;
	}
	return (1);
}

static int add_input_request(t_data_rule *request, t_split *split)
{
	if (!split)
		return (0);
	request->input = split->word;
	printf("add_ : %s\n", split->word);
	return (1);
}

static int fill_request(t_split *split, t_data_rule *request, int count_word, int k)
{
	int nb_node;


	nb_node = 0;
	if (count_word <= 0)
		return (0);
	nb_node = r_node(split, 0);
	if (nb_node == -1)
		return (-1);
	add_command(&request[k], split);
	request[k].nbr_args = nb_node;
	if (nb_node > 1)
	{
		request[k].arguments = ft_calloc(sizeof(char *), nb_node + 1);
		add_arg_request(&request[k], split + 1, nb_node);
	}
	request[k].pipe = false;
	request->oper = converte_rdir(&request[k], &split[nb_node]);
	printf("oper : %c\n", request->oper);
	if (count_word > nb_node)
	{
		nb_node++;
		if (request->oper == INPUT && nb_node < count_word)
			add_input_request(&request[k], split + (nb_node - 2));
		if ((request->oper == RDIR || request->oper == D_RDIR) && nb_node < count_word)
			add_out_request(&request[k], split + nb_node);
		nb_node++;
	}
	if (add_pipe(&request[k], split + nb_node, count_word) && nb_node < count_word)
		nb_node++;
	count_word -= nb_node;
	return (fill_request(split + nb_node, request, count_word, k + 1));
}

t_data_rule		*parsing_tree(t_split *split, const int count_word)
{
	t_data_rule *out;
	int i = 0;
	int k = 0;

	out = ft_calloc(sizeof(t_data_rule), nb_command(split, count_word));
	if (!out)
		return (NULL);
	out->nb_command = nb_command(split, count_word);
	if (fill_request(split, &out[k], count_word, 0) == -1) {
		free(out);
		return NULL;
	}
	if (1)
	{
		while (k < nb_command(split, count_word)) {
			i = 0;
			printf("-----------------\n");
			printf("count_word : %d\n", count_word);
			printf("command : %s\n", out[k].command);
			if (out[k].arguments)
			{
				while (out[k].arguments[i]) {
					printf("arg[%d] : %s\n", i, out[k].arguments[i]);
					i++;
				}
			}
			printf("out : %s\n", out[k].out);
			printf("input : %s\n", out[k].input);
			printf("oper : %c\n", out[k].oper);
			printf("pipe : %B\n", out[k].pipe);
			k++;
		}
		printf("-----------------\n");
	}
	return (out);
}