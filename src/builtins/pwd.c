/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:35:49 by raphox            #+#    #+#             */
/*   Updated: 2025/01/29 16:13:33 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char *command, char **envv)
{
	char	pwd[10000];

	getcwd(pwd, sizeof(pwd));
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	return ;
}
