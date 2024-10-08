/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:29:11 by raphox            #+#    #+#             */
/*   Updated: 2024/10/08 12:43:24 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include "../includes/libft.h"

void exec_builtins(t_data_rule struc)
{
	if (ft_strncmp(struc.command, "cd", ft_strlen(struc.command)) == 0)
	{
		cd(struc.command, struc.arguments, struc.envv);
		// voir pour chemin relatif
	}
	else if (ft_strncmp(struc.command, "echo", ft_strlen(struc.command)) == 0)
		echo(struc.command, struc.options, struc.arguments);
		
	else if (ft_strncmp(struc.command, "env", ft_strlen(struc.command)) == 0)
		display_env(struc.envv);
	
	else if (ft_strncmp(struc.command, "export", ft_strlen(struc.command)) == 0)
	{
		export(struc.command, struc.arguments, struc.envv);
		// revoir export
	}
	else if (ft_strncmp(struc.command, "pwd", ft_strlen(struc.command)) == 0)
		pwd(struc.command, struc.envv);
	
	
	else if (ft_strncmp(struc.command, "unset", ft_strlen(struc.command)) == 0)
		unset_var(struc.envv, struc.arguments[0]);
}

int	find_in_envv(char **envv, char *var)
{
	int i;
	i = 0;
	
	if (var == NULL)
		return (-1);
	while (envv[i] != NULL)
	{
		if (strncmp(envv[i], var, strlen(var)) == 0 && envv[i][strlen(var)] == '=')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}