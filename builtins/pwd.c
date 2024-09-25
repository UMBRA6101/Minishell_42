/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:35:49 by raphox            #+#    #+#             */
/*   Updated: 2024/09/24 18:00:37 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/Lexing.h"
#include "../includes/libft.h"

void pwd(char *command, char **arguments, char **envp)
{
	if (command[0] == 'p' && command[1] == 'w' && command[2] == 'd')
		printf("%s", (envp[64] + 4));

}

// int main(int agrc, char **argv, char **envp)
// {
// 	pwd("pwd", "", envp);
	
// }