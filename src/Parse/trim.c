/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:13:38 by thodos-s          #+#    #+#             */
/*   Updated: 2025/02/05 14:42:36 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*	deletion of useless space	*/
int	trim_space(char *str)
{
	int	itr_str;

	itr_str = ft_strlen(str) - 1;
	if (itr_str < 0)
		return (1);
	while (itr_str >= 0)
	{
		if (!ft_isspace(str[itr_str]))
			break ;
		str[itr_str] = '\0';
		itr_str--;
	}
	return (0);
}

/*	deletion of useless quote	*/
int	trim_quote(char *str)
{
	bool	sq;
	bool	dq;
	int		i;

	i = 0;
	sq = false;
	dq = false;
	while (str[i])
	{
		quote_id(&sq, &dq, &i, str[i]);
		if (str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
	}
	if (sq || dq)
		return (-1);
	return (0);
}

/*	deletion of all useless element	*/
int	trim_useless(char **str, t_erreur *err)
{
	if (trim_space(*str))
		return (1);
	if (ft_strlen(*str) <= 0)
	{
		err->error_code = -1;
		return (1);
	}
	if (trim_quote(*str))
	{
		err->error_code = STX_NL;
		return (1);
	}
	return (0);
}
