/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:10:56 by raphox            #+#    #+#             */
/*   Updated: 2025/01/23 04:52:50 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char *command, char **option, char **arguments)
{
	int		i;
	char	*result;
	char	*temp;

	i = 0;
	result = ft_strdup("");
	if (arguments != NULL)
	{
		free(result);
		result = ft_strdup(arguments[0]);
		i = 1;
		while (arguments[i] != NULL)
		{
			temp = ft_strjoin(result, arguments[i], 1);
			free(result);
			result = temp;
			i++;
		}
	}
	display_echo(command, option, arguments, result);
	free(result);
}

void	display_echo(char *command, char **option, char **arguments,
		char *result)
{
	char	*content;

	if (command != NULL && option == 0 && arguments == 0)
	{
		write(1, "\n", 1);
		write_temp_file(TMP_FILES, 0);
		return ;
	}
	if (command != NULL && option == NULL && arguments[0][0] == '$'
		&& arguments[0][1] == '?' && arguments[0][2] == '\0')
	{
		content = read_temp_file(TMP_FILES);
		write(1, content, ft_strlen(content));
		free(content);
		write(1, "\n", 1);
	}
	else
	{
		display_echo_2(command, option, arguments, result);
	}
}

int	display_echo_2(char *command, char **option, char **arguments, char *result)
{
	if (command != NULL && option != NULL && option[0][0] == '-'
		&& option[0][1] == 'n' && option[0][2] == '\0' && arguments == 0)
	{
		write_temp_file(TMP_FILES, 0);
		return (0);
	}
	else if (command != NULL && option == NULL && arguments != NULL)
	{
		write(1, result, ft_strlen(result));
		write_temp_file(TMP_FILES, 0);
		write(1, "\n", 1);
		return (0);
	}
	else if (command != NULL && option != NULL && option[0][0] == '-'
		&& option[0][1] == 'n' && option[0][2] == '\0' && arguments != 0)
		write(1, result, ft_strlen(result));
	write_temp_file(TMP_FILES, 0);
	return (0);
}

int	check_whole_n(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i] == 'n' && str[i] != '\0')
	{
		i++;
	}
	if (i == ft_strlen(str))
	{
		return (1);
	}
	else
		return (0);
}
