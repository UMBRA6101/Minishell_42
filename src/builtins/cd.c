/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:30:17 by raphox            #+#    #+#             */
/*   Updated: 2024/10/08 12:56:35 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include "../includes/libft.h"


void cd(char *command, char **arguments, char **envp)
{
	const char *path;
	const char *user;
	
	if (command != 0 && arguments[0] == '\0') // > cd (fait mais inutile, car pas demander)
	{
		chdir(getenv("HOME"));
		// printf("%d",chdir(path));
	}
	if (command != 0 && arguments[0] != 0) // > cd "arguments"
	{
		chdir(arguments);
		envp[64] = arguments;
	}
}

// int main(int argc, char **argv, char **envp)
// {
// 	char command[] = "cd";
// 	char arguments[] = "/home/raphox/Desktop";
// 	// printf("%s", envp[3]);
// 	cd(command, arguments, envp);
// }