/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:51:39 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/23 03:51:45 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by umbra on 12/10/24.
//
#include "../../includes/minishell.h"

/*	free vital element	*/
void	free_all(t_info **info, char *rule, int ext)
{
	if (rule)
		free(rule);
	if ((*info)->envv)
		free_env((*info)->envv);
	free((*info)->err);
	free(*info);
	rl_clear_history();
	if (ext != -1)
		exit (ext);
}
