/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:47:30 by raphox            #+#    #+#             */
/*   Updated: 2024/10/29 16:57:24 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// envp deja copier auparavant !!!!!! sinon ne marche pas !!!!!!!

#include "pipex_bonus.h"
#include "libft/libft.h"

char **unset(char *command, const char **arguments, char **envp)
{
	int i;
	i = 0;

	if (arguments == NULL)
	{
		return (envp);
	}
	
	else
		while (arguments[i])
		{
			cmd_unset(envp, arguments[i++]);
		}
	return (envp);
		
}

char	**cmd_unset(char **env, const char *var)
{
	int i;
	i = 0;

	if (var == NULL)
		return (NULL);
	
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, strlen(var)) == 0 && env[i][ft_strlen(var)] == '=')
		{
			while (env[i] != NULL) 			// ca decale les autres variables
			{
				env[i] = env[i + 1];
				i++;
			}
			// free(env[i]); // supp la variable en faisant free
			return (env);
		}
		i++;
	}
	return (env);
}


// int main(int argc, char **argv, char **envp)
// {
// 	char **enviro;
// 	enviro = copy_env(envp);
// 	enviro = unset_var(enviro, argv[1]);
// 	return (0);

// }