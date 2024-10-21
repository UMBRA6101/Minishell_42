/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:28:32 by raphox            #+#    #+#             */
/*   Updated: 2024/10/13 22:50:29 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include "../includes/libft.h"

// envp est une copie ! ! ! ! !!


char	**export(char *command, const char **arguments, char **env)
{
	int		i;
	char	**result;
	char	**new_result;

	i = 0;
	result = env;
	bubble_sort(result);
	if (command != NULL && arguments == NULL)
		display_x_variables(result);
	else
	{
		while (arguments[i] != NULL)
		{
			new_result = cmd_export(command, arguments[i++], result);
			if (new_result != result && result != env)
				free_env(result);
			result = new_result;
		}
		i = 0;
		while (result[i] != NULL)
			printf("declare -x %s\n", result[i++]);
	}
	if (result != env)
		free_env(result);
	return (env);
}

// Fonction cmd_export qui ajoute un nouvel argument à l'environnement
char	**cmd_export(char *command, const char *argument, char **env)
{
	char	**new_env;
	int		size;

	if (command == NULL || argument == NULL)
		return (env);
	new_env = allocate_new_env(env);
	if (!new_env)
		exit(EXIT_FAILURE);
	size = copy_env(env, new_env);
	if (size == -1)
		exit(EXIT_FAILURE);
	new_env[size] = strdup(argument);
	if (!new_env[size])
	{
		free_env(new_env);
		exit(EXIT_FAILURE);
	}
	new_env[size + 1] = NULL;
	return (new_env);
}

// Fonction pour allouer le nouvel environnement
char	**allocate_new_env(char **env)
{
	int		size;
	char	**new_env;

	size = 0;
	while (env[size])
		size++;
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
		return (NULL);
	return (new_env);
}

// Fonction pour copier les anciennes variables d'environnement dans le nouvel environnement
int		copy_env(char **env, char **new_env)
{
	int		j;

	j = 0;
	while (env[j] != NULL)
	{
		new_env[j] = strdup(env[j]);
		if (!new_env[j])
		{
			free_env(new_env);
			return (-1);
		}
		j++;
	}
	return (j);
}







//-------------------------------------------------------------------------
