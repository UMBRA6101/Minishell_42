/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:29:11 by raphox            #+#    #+#             */
/*   Updated: 2024/09/24 17:28:29 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/Lexing.h"
#include "../includes/libft.h"

void exec_builtins(t_data_rule struc)
{
	if (ft_strncmp(struc.command, "cd", ft_strlen(struc.command)) != 0)
	{
		cd(struc.command, struc.arguments, struc.env);
		// voir pour chemin relatif
	}
	if (ft_strncmp(struc.command, "echo", ft_strlen(struc.command)) != 0)
		echo(struc.command, struc.options, struc.arguments);
		
	if (ft_strncmp(struc.command, "env", ft_strlen(struc.command)) != 0)
		display_env(struc.env);
	if (ft_strncmp(struc.command, "export", ft_strlen(struc.command)) != 0)
	{
		export(struc.command, struc.env);
		// revoir export
	}
	if (ft_strncmp(struc.command, "pwd", ft_strlen(struc.command)) != 0)
		pwd(struc.command, struc.arguments, struc.env);
	if (ft_strncmp(struc.command, "unset", ft_strlen(struc.command)) != 0)
		unset_var(struc.env, struc.arguments);
}