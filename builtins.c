/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:29:11 by raphox            #+#    #+#             */
/*   Updated: 2024/11/06 15:42:40 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

char **exec_builtins(t_data_rule struc, char **envp)
{
	
	if (ft_strncmp(struc.command, "cd", ft_strlen(struc.command)) == 0) // modidfy env
	{
		// envp = cd(struc.command, struc.arguments, envp);
		return(envp);
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
	else if (ft_strncmp(struc.command, "export", ft_strlen(struc.command)) == 0) // modidfy env
	{	
		envp = export(struc.command, struc.arguments, envp);
		// display_env(envp);
		return (envp);
	}
	else if (ft_strncmp(struc.command, "pwd", ft_strlen(struc.command)) == 0)
	{
		pwd(struc.command, envp);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(struc.command, "unset", ft_strlen(struc.command)) == 0) // modidfy env
	{
			envp = unset(struc.command, struc.arguments, envp);
			// printf("RESULT ENV ----------------------------------------------------------------------------\n\n\n");
			// display_env(envp);
			return (envp);
			

	}
	return (envp);
}



int check_if_in_builtins(t_data_rule struc, char **envp)
{
	
	if (ft_strncmp(struc.command, "cd", ft_strlen(struc.command)) == 0) // modidfy env
		return(-1);
	else if (ft_strncmp(struc.command, "echo", ft_strlen(struc.command)) == 0)
		return(1);
	else if (ft_strncmp(struc.command, "env", ft_strlen(struc.command)) == 0)
		return(1);
	else if (ft_strncmp(struc.command, "export", ft_strlen(struc.command)) == 0) // modidfy env
		return(-1);
	else if (ft_strncmp(struc.command, "pwd", ft_strlen(struc.command)) == 0)
		return(1);
	else if (ft_strncmp(struc.command, "unset", ft_strlen(struc.command)) == 0) // modidfy env
		return(-1);
	return (0);
}
