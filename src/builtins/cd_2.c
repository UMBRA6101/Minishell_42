/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:02:35 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/23 03:40:59 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*build_resolved_path(char **segments, int segment_count)
{
	char	*resolved_path;
	int		j;
	int		i;

	resolved_path = malloc(1024);
	if (!resolved_path)
	{
		i = 0;
		while (i < segment_count)
			free(segments[i++]);
		return (NULL);
	}
	resolved_path[0] = '/';
	resolved_path[1] = '\0';
	j = 0;
	while (j < segment_count)
	{
		ft_strlcat(resolved_path, segments[j], 1024);
		if (j < segment_count - 1)
			ft_strlcat(resolved_path, "/", 1024);
		free(segments[j]);
		j++;
	}
	return (resolved_path);
}

char	*custom_realpath(const char *path)
{
	char	*segments[256];
	int		segment_count;

	parse_segments(path, segments, &segment_count);
	return (build_resolved_path(segments, segment_count));
}

void	handle_cd_errors(char **arguments)
{
	DIR	*dir;

	if (count_arguments(arguments) >= 2)
	{
		write_temp_file(TMP_FILES, 1);
		write(2, "cd: too many arguments\n", 23);
		return ;
	}
	dir = opendir(arguments[0]);
	if (dir == NULL)
	{
		display_error("cd", NULL, arguments, 0);
		write_temp_file(TMP_FILES, 1);
		return ;
	}
	closedir(dir);
}
