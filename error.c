/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:55 by raphox            #+#    #+#             */
/*   Updated: 2024/11/13 18:04:07 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

void	handle_free(char **envp)
{
	free_env(envp);
	envp = NULL;
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return ;
	while (env != NULL && env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
	if (env != NULL)
		free(env);
	// env = NULL;
}