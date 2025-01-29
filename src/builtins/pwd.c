/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:35:49 by raphox            #+#    #+#             */
/*   Updated: 2025/01/29 12:30:48 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	pwd(char *command, char **envv)
// {
// 	int	index;

// 	index = find_in_envv(envv, "PWD");
// 	if (index == -1)
// 	{
// 		write_temp_file(TMP_FILES, 1);
// 		return ;
// 	}
// 	if (ft_strncmp(command, "pwd", ft_strlen(command)) == 0)
// 	{
// 		write(1, envv[index] + 4, ft_strlen(envv[index] + 4));
// 		write(1, "\n", 1);
// 	}
// 	return ;
// }


void	pwd(char *command, char **envv)
{
	char pwd[10000];

	getcwd(pwd, sizeof(pwd));
	write(1, pwd, ft_strlen(pwd));
	return ;
}
