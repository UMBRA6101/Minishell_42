/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:30:17 by raphox            #+#    #+#             */
/*   Updated: 2025/01/29 15:24:02 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env(char **envp, char *old_pwd, char *new_pwd)
{
	int	oldpwd_index;
	int	pwd_index;

	oldpwd_index = find_in_envv(envp, "OLDPWD");
	if (oldpwd_index != -1)
	{
		free(envp[oldpwd_index]);
		envp[oldpwd_index] = ft_strjoin("OLDPWD=", old_pwd, 0);
		
	}
		
	pwd_index = find_in_envv(envp, "PWD");
	if (pwd_index != -1)
	{
		free(envp[pwd_index]);
		envp[pwd_index] = ft_strjoin("PWD=", new_pwd, 0);
	}
}

char	**cd(char *command, char **args, char **envp)
{
	char	old_pwd[1024];
	char	npwd[1024];
	char	*rslvepath;
	char	*home;

	getcwd(old_pwd, sizeof(old_pwd));
	if (args != NULL && (args[0][0] == '.' && args[0][1] == '\0') || (handle_cd_errors(args) == -1))
		return (envp);
	if (command != NULL && args == NULL)
		chdir(home = getenv("HOME"));
	else if (command != NULL && args != NULL && strcmp(args[0], "..") == 0)
		chdir("..");
	else if (command != NULL && args != NULL && args[0][0] == '/')
		chdir(args[0]);
	else if (command != NULL && args != NULL && args[0][0] != '/')
	{
		(getcwd(npwd, sizeof(npwd)), rslvepath = resolve_path(npwd, args[0]));
		if (rslvepath == NULL)
			return (NULL);
		(chdir(rslvepath), free(rslvepath));
	}
	return (getcwd(npwd, sizeof(npwd)),
		update_env(envp, old_pwd, npwd), envp);
}

char	*resolve_path(const char *cwd, const char *relative_path)
{
	char	*path;
	char	*resolved_path;
	size_t	cwd_len;
	size_t	rel_len;

	cwd_len = ft_strlen(cwd);
	rel_len = ft_strlen(relative_path);
	path = malloc(cwd_len + rel_len + 2);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, cwd, cwd_len + 1);
	ft_strlcat(path, "/", cwd_len + 2);
	ft_strlcat(path, relative_path, cwd_len + rel_len + 2);
	resolved_path = custom_realpath(path);
	free(path);
	return (resolved_path);
}

void	parse_segments(const char *path, char **segments, int *segment_count)
{
	char	temp[1024];
	int		start;
	int		end;

	*segment_count = 0;
	ft_strlcpy(temp, path, sizeof(temp));
	start = 0;
	while (temp[start] != '\0')
	{
		while (temp[start] == '/')
			start++;
		if (temp[start] == '\0')
			break ;
		end = start;
		while (temp[end] != '/' && temp[end] != '\0')
			end++;
		temp[end] = '\0';
		handle_special_segments(temp, segments, segment_count, start);
		start = end + 1;
	}
}

void	handle_special_segments(char *temp, char **segments,
		int *segment_count, int start)
{
	int	i;

	i = 0;
	if (ft_strncmp(temp + start, "..", 3) == 0)
	{
		if (*segment_count > 0)
		{
			free(segments[*segment_count - 1]);
			(*segment_count)--;
		}
	}
	else if (ft_strncmp(temp + start, ".", 2) != 0)
	{
		segments[*segment_count] = ft_strdup(temp + start);
		if (segments[*segment_count] == NULL)
		{
			while (i < *segment_count)
				free(segments[i++]);
			return ;
		}
		(*segment_count)++;
	}
}
