/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_tree_adder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:24:22 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/22 11:54:03 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.h"

/*	add executable in struct	*/
int	add_command(t_data_rule *request, t_split *split)
{
	if (!split)
		return (-1);
	if (check_rdir(split[0].word, ft_strlen(split[0].word)) == D_INPUT)
	{
		request->command = ft_strdup("cat");
		return (0);
	}
	else
		request->command = ft_strdup(split[0].word);
	return (1);
}

/*	add in struct if pipe exist	*/
int	add_pipe(t_data_rule *request, t_split *split, const int count_word)
{
	if (count_word <= 0 || !split)
		return (0);
	if (split->word && ft_strncmp(split->word, "|", split->len_word) == 0)
	{
		request->pipe = true;
		return (1);
	}
	return (0);
}

/*	add option of executable */
int	add_opt_request(t_data_rule *request,
			t_split *split, const int nb_opt)
{
	int	i;

	i = 0;
	request->options = ft_calloc(sizeof(char *), nb_opt + 1);
	if (!request->options)
		return (-1);
	while (i < nb_opt)
	{
		request->options[i] = ft_strdup(split[i].word);
		i++;
	}
	request->nb_opt = nb_opt;
	return (1);
}
