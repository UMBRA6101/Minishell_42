/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_command_builder_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:25:37 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/22 22:26:00 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_options(char **options, int *option_count)
{
	int	i;

	i = 0;
	if (options == NULL)
	{
		*option_count = 0;
		return (0);
	}
	while (options[i] != NULL)
		i++;
	*option_count = i;
	return (1);
}

int	is_directory(const char *path)
{
	struct stat	path_stat;

	if (lstat(path, &path_stat) == -1)
	{
		return (0);
	}
	return (S_ISDIR(path_stat.st_mode));
}

int	check_slash(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
