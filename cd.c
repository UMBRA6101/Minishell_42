/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:30:17 by raphox            #+#    #+#             */
/*   Updated: 2024/10/29 16:57:51 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex_bonus.h"
#include "libft/libft.h"


void cd(char *command, const char **arguments, char **envp)
{
	
	if (command != 0 && arguments == 0) // > cd (fait mais inutile, car pas demander)
		chdir(getenv("HOME"));
			
		// printf("%s",getenv("PWD"));
	
	else if (command != 0 && arguments != 0 && (arguments[0][0] == '/')) // > cd "arguments"
	{
			chdir(arguments[0]);
			return ;
	}

	else if ((command != 0 && arguments != 0 && arguments[0][0] != '/'))
	{
		char *pwd;
		char *short_path;
		char *result_path;
		
		char slash[] = "/";
		pwd = getenv("PWD");
		
		short_path = ft_strjoin(pwd, slash, 0);
		result_path = ft_strjoin(short_path, arguments[0], 0);
		
		chdir(result_path);
		
		free(short_path);
		free(result_path);
	}
	return ;
}

// int main(int argc, char **argv, char **envp)
// {
// 	char command[] = "cd";
// 	char arguments[] = "/home/raphox/Desktop";
// 	// printf("%s", envp[3]);
// 	cd(command, arguments, envp);
// }