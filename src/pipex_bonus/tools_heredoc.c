/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:53:54 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/27 19:42:54 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_h_is_find(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'h')
			count++;
		i++;
	}
	if (count > 0)
		return (count);
	else
		return (0);
}

int	get_h_position(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'h')
			count = i;
		i++;
	}
	return (count);
}

int	give_latest_heredoc(t_data_rule data)
{
	int	i;
	int	result;

	i = 0;
	result = -1;
	while (data.oper[i] != '\0')
	{
		if (data.oper[i] == 'h')
		{
			result = handle_heredoc(data.out[i]);
			if (get_h_position(data.oper) == i)
			{
				return (result);
			}
			else if (result == -1)
				return (-1);
			else
				close(result);
		}
		i++;
	}
	return (0);
}

void	free_heredoc(int *tab_heredoc, int num_commands)
{
	int	k;

	k = 0;
	if (tab_heredoc == NULL)
		return ;
	while (k < num_commands + 1)
	{
		if (tab_heredoc[k] != -1 && tab_heredoc[k] != 0)
		{
			close(tab_heredoc[k]);
		}
		k++;
	}
	if (tab_heredoc != NULL)
		free(tab_heredoc);
}
