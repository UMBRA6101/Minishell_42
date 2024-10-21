/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:55 by raphox            #+#    #+#             */
/*   Updated: 2024/10/19 17:54:41 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/libft.h"

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return ;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}