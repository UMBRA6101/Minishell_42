/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:45:55 by raphox            #+#    #+#             */
/*   Updated: 2025/01/27 13:02:54 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}

// export suite 2

int	check_export_before_equal(char *args)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (args[i] != '\0')
	{
		if (args[i] == '=')
		{
			found++;
			break ;
		}
		if ((args[0] >= '0' && args[0] <= '9') || (args[i] == '!'
				|| args[i] == '$' || args[i] == ' ' || args[i] == '#'
				|| args[i] == '-'))
			return (write(2, "export: not a valid identifier\n", 31), -1);
		i++;
	}
	if ((i == 0 && found == 1))
		return (write(2, "export: not a valid identifier\n", 31), -1);
	if (found == 0)
		return (write_temp_file(TMP_FILES, 0), 0);
	return (0);
}
