/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:47:30 by raphox            #+#    #+#             */
/*   Updated: 2024/09/24 16:18:15 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// envp deja copier auparavant !!!!!! sinon ne marche pas !!!!!!!

#include "../includes/minishell.h"
#include "../includes/Lexing.h"
#include "../includes/libft.h"


void display_env(char **envp)
{
	int i;
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

void	unset_var(char **env, const char *var)
{
	int i;
	i = 0;
	
	if (var == NULL)
		return ;
	while (env[i] != NULL)
	{
		if (strncmp(env[i], var, strlen(var)) == 0 && env[i][strlen(var)] == '=')
		{
			// free(env[i]); // supp la variable en faisant free
			while (env[i] != NULL) 			// ca decale les autres variables
			{
				env[i] = env[i + 1];
				i++;
			}
			display_env(env);
			// printf("\n\n\nbine jouer mon gars \n\n\n");
			return ;
		}
		i++;
	}
	return ;
}

static char  **copy_env(char **envp)
{
	static char **env;
	env = envp;
	return (env);
}


// int main(int argc, char **argv, char **envp)
// {
// 	char **enviro;
// 	enviro = copy_env(envp);
// 	enviro = unset_var(enviro, argv[1]);
// 	return (0);

// }