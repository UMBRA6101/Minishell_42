/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:47:30 by raphox            #+#    #+#             */
/*   Updated: 2025/01/22 20:05:42 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// envp deja copier auparavant !!!!!! sinon ne marche pas !!!!!!!

#include "minishell.h"

char	**unset(char **arguments, char **envp)
{
	int	i;

	i = 0;
	if (arguments == NULL)
	{
		write_temp_file(TMP_FILES, 0);
		return (envp);
	}
	else
		while (arguments[i])
			envp = cmd_unset(envp, arguments[i++]);
	return (envp);
}

char	**cmd_unset(char **env, char *var)
{
	int	i;

	i = 0;
	if (var == NULL)
		return (env);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0 && check_var(var) == 1)
		{
			free(env[i]);
			while (env[i] != NULL)
			{
				env[i] = env[i + 1];
				i++;
			}
			return (env);
		}
		i++;
	}
	return (env);
}

int	check_var(char *str)
{
	int	size;
	int	size_var;

	size = 0;
	size_var = ft_strlen(str);
	while (str[size])
	{
		if (str[size] == '=')
			return (0);
		size++;
	}
	return (1);
}
