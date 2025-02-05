/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:09:05 by thodos-s          #+#    #+#             */
/*   Updated: 2025/02/05 14:41:47 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../includes/Parsing.h"

void	killer_split(t_split *split, const int nb_word)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (i <= nb_word)
		free(split[i++].word);
	free(split);
}

static void	killer_array(char **buff, const int len)
{
	int	itr;

	itr = 0;
	(void)len;
	if (!(*buff) || !buff || len <= 0)
		return ;
	while (buff[itr])
	{
		free(buff[itr]);
		itr++;
	}
	free(buff);
	buff = NULL;
}

void	killer_request(t_data_rule *request)
{
	int	k;
	int	nb_command;

	k = 0;
	if (!(request))
		return ;
	nb_command = request[0].nb_command;
	while (k < nb_command)
	{
		if (request[k].command)
			free(request[k].command);
		if (request[k].nbr_args > 0 && request[k].arguments)
			killer_array(request[k].arguments, request[k].nbr_args);
		if (request[k].nb_rdir > 0)
		{
			killer_array(request[k].out, request[k].nb_rdir);
			free(request[k].oper);
		}
		if (request[k].nb_opt > 0)
			killer_array(request[k].options, request[k].nb_opt);
		if (request[k].input != NULL)
			free(request[k].input);
		k++;
	}
	free(request);
}
