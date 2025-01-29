/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:49:10 by raphox            #+#    #+#             */
/*   Updated: 2025/01/22 22:31:32 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_x_variables(char **result)
{
	int		fd[2];
	char	buffer[100000];
	size_t	bytes_read;
	int		i;

	pipe(fd);
	i = 0;
	while (result[i] != NULL)
	{
		write(fd[1], "declare -x ", 11);
		write(fd[1], result[i], ft_strlen(result[i]));
		write(fd[1], "\n", 1);
		i++;
	}
	bytes_read = read(fd[0], buffer, sizeof(buffer));
	write(1, buffer, bytes_read);
	close(fd[0]);
	close(fd[1]);
}

int	find_in_envv(char **envv, char *var)
{
	int	i;

	i = 0;
	if (var == NULL)
		return (-1);
	while (envv[i] != NULL)
	{
		if (strncmp(envv[i], var, strlen(var)) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	compare_strings(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

void	bubble_sort(char **envp)
{
	int	i;
	int	swapped;
	int	len;

	len = 0;
	while (envp[len])
		len++;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < len - 1)
		{
			if (envp[i] && envp[i + 1] && compare_strings(envp[i],
					envp[i + 1]) > 0)
			{
				swap(&envp[i], &envp[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
	display_x_variables(envp);
}
