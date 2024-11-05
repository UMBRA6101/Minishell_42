/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:30:17 by raphox            #+#    #+#             */
/*   Updated: 2024/11/04 21:07:57 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex_bonus.h"
#include "libft/libft.h"


char **cd(char *command, const char **arguments, char **envp)
{
	char *oldpwd;
	oldpwd = getenv("PWD");

	if (command != 0 && arguments == 0) // > cd (fait mais inutile, car pas demander)		
		chdir(getenv("HOME"));
			
		// printf("%s",getenv("PWD"));
	else if (command != 0 && arguments != 0 && (arguments[0][0] == '/')) // > cd "arguments"
	{
		ft_strlcat(envp[find_in_envv(envp, "PWD")], arguments[0], ft_strlen(arguments[0] - 6));
		display_env(envp);
		return (NULL);
		
		chdir(arguments[0]);
		return (NULL);
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
	return (NULL);
}



// int main(int argc, char **argv, char **envp)
// {
// 	char command[] = "cd";
// 	char arguments[] = "/home/raphox/Desktop";
// 	// printf("%s", envp[3]);
// 	cd(command, arguments, envp);
// }