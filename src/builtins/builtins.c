/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:29:11 by raphox            #+#    #+#             */
/*   Updated: 2024/10/13 22:52:57 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include "../includes/libft.h"

void exec_builtins(t_data_rule struc, char **envp)
{
	int i;
	i = 0;

	
	if (ft_strncmp(struc.command, "cd", ft_strlen(struc.command)) == 0)
	{
		cd(struc.command, struc.arguments, envp);
		// voir pour chemin relatif
	}
	else if (ft_strncmp(struc.command, "echo", ft_strlen(struc.command)) == 0)
		echo(struc.command, struc.options, struc.arguments);
			
	else if (ft_strncmp(struc.command, "env", ft_strlen(struc.command)) == 0)
		display_env(envp);
	
	else if (ft_strncmp(struc.command, "export", ft_strlen(struc.command)) == 0)
	{	
		envp = export(struc.command, struc.arguments, envp);
	}
	else if (ft_strncmp(struc.command, "pwd", ft_strlen(struc.command)) == 0)
		pwd(struc.command, envp);
	else if (ft_strncmp(struc.command, "unset", ft_strlen(struc.command)) == 0)
	{
			envp = unset(struc.command, struc.arguments, envp);
	}
}

