/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:29:11 by raphox            #+#    #+#             */
/*   Updated: 2024/10/30 16:37:03 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

int exec_builtins(t_data_rule struc, char **envp)
{	
	if (ft_strncmp(struc.command, "cd", ft_strlen(struc.command)) == 0)
	{
		cd(struc.command, struc.arguments, envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "echo", ft_strlen(struc.command)) == 0)
	{
		echo(struc.command, struc.options, struc.arguments);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "env", ft_strlen(struc.command)) == 0)
	{
		display_env(envp);
		exit(EXIT_SUCCESS);
	}
	
	else if (ft_strncmp(struc.command, "export", ft_strlen(struc.command)) == 0)
	{	
		envp = export(struc.command, struc.arguments, envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "pwd", ft_strlen(struc.command)) == 0)
	{
		pwd(struc.command, envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "unset", ft_strlen(struc.command)) == 0)
	{
			envp = unset(struc.command, struc.arguments, envp);
			// printf("RESULT ENV ----------------------------------------------------------------------------\n\n\n");
			// display_env(envp);
			exit(EXIT_SUCCESS);

	}
	return (0);
}

