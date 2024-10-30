/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:35:49 by raphox            #+#    #+#             */
/*   Updated: 2024/10/29 16:57:29 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

void pwd(char *command, char **envv)
{
	int index;
	index = find_in_envv(envv, "PWD");
	
	if (command[0] == 'p' && command[1] == 'w' && command[2] == 'd')
		printf("%s\n", (envv[index] + 4));
	return ;

}

// int main(int agrc, char **argv, char **envp)
// {
// 	pwd("pwd", "", envp);
	
// }