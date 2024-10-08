/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:27:14 by raphox            #+#    #+#             */
/*   Updated: 2024/10/08 12:04:19 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/libft.h"

// MA PARTIE

//je recois la struct allouer avec tous les command, options, arguments, etc...



void malloc_struc()
{
	int i;
	i = 0;
	t_data_rule first;
	first.command = "pwd";
	first.options = NULL;
	first.arguments = NULL;
	first.envv = NULL;
	
	exec_builtins(first);
	
}