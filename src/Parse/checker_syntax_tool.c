/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_syntax_tool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:23:54 by thodos-s          #+#    #+#             */
/*   Updated: 2024/11/20 12:23:55 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.h"

int	empty_braquet(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '(')
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == ')')
		return (1);
	return (0);
}

int	valid_braquet(char *str, int *b_left, int *b_right)
{
	bool	sq;
	bool	dq;
	int		i;

	sq = false;
	dq = false;
	i = 0;
	while (str[i])
	{
		quote_id(&sq, &dq, NULL, str[i]);
		if (str[i] == '(' && empty_braquet(str + i) && (!sq && !dq))
			return (-1);
		if (str[i] == '(' && (!sq && !dq))
			(*b_left)++;
		if (str[i] == ')' && (!sq && !dq))
			(*b_right)++;
		i++;
	}
	return (0);
}
