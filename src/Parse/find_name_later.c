/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_name_later.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:08:12 by thodos-s          #+#    #+#             */
/*   Updated: 2025/02/05 14:41:32 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.h"

/*	identify other character	*/
int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/*	identify redirection	*/
int	is_rdir(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

/*	identify operator	*/
int	is_oper(char c)
{
	if (c == '|' || c == ';')
		return (1);
	return (0);
}

/*	end condition	*/
int	ft_isend(const char c)
{
	if (ft_isspace(c) || c == '|' || c == ';' || is_rdir(c))
		return (1);
	return (0);
}

int	state_finish(t_token *token)
{
	return (token->nb_word);
}
