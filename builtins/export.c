/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:28:32 by raphox            #+#    #+#             */
/*   Updated: 2024/09/24 19:05:26 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/minishell.h"
#include "../includes/Lexing.h"
#include "../includes/libft.h"
//envp est une copie ! ! ! ! !! 

void export(char *command, char **arguments, char **env)
{
	char **new_env;
	int i;
	int j;
	j = 0;
	i = 0;


	if (command != NULL && arguments == NULL)
	{
		while (env[i] != NULL)
		{
			printf("declare -x %s\n", envp[i]);
			i++;
		}
	}
	else
	{
		while (env[i])
			i++;
		new_env = malloc(sizeof(char *) * (i + 2));
		i = 0;
	
		while (env[i])
		{
			new_env[i] = env[i];
			i++;
		}
		new_env[i] = ft_strdup(arguments[0]);
		i++;
		new_env[i] = 0;		
	}

	int l;
	l = 0;
	while (new_env[l])
	{
		printf("%s", new_env[l]);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	char **str[0] = "var = ma teub";
	export("export", str, envp);
}