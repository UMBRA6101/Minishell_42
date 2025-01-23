/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:08:20 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/22 11:53:29 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.h"

/*	convert redirection and add in the structur	*/
void	fill_conv_rdir(t_data_rule *request, const int rdir, const int itr_oper)
{
	if (rdir == D_RDIR)
		request->oper[itr_oper] = 'r';
	if (rdir == RDIR)
		request->oper[itr_oper] = '>';
	if (rdir == D_INPUT)
		request->oper[itr_oper] = 'h';
	if (rdir == INPUT)
		request->oper[itr_oper] = '<';
}

int	ft_occ(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == c)
		i++;
	return (i);
}

int	echo_test(t_data_rule *rqst, t_split *split, int nb_node)
{
	if (ft_strncmp(rqst->command, "echo", ft_strlen(rqst->command)) == 0)
	{
		if (nb_node >= 2)
		{
			if (ft_strlen(split[1].word) != ft_occ(split[1].word + 1, 'n') + 1)
				return (1);
		}
	}
	return (0);
}
