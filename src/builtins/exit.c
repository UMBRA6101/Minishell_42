/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:06:10 by raphox            #+#    #+#             */
/*   Updated: 2025/01/22 21:49:32 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_arguments(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_is_real_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+'))
			return (-1);
		i++;
	}
	return (0);
}

int	built_exit(char **arguments)
{
	int	n;

	n = 0;
	if (arguments == NULL)
	{
		return (1);
	}
	if (count_arguments(arguments) >= 2)
	{
		if (ft_is_real_digit(arguments[0]) == 0)
		{
			write(2, "bash: exit: too many arguments\n", 31);
			write_temp_file(TMP_FILES, 1);
			return (1);
		}
		else
		{
			write_temp_file(TMP_FILES, 2);
			write(2, "bash: EXIT: too many arguments\n", 31);
			return (1);
		}
	}
	if (built_exit_2(arguments) == 1)
		return (1);
	return (0);
}

int	built_exit_2(char **arguments)
{
	int	n;

	n = 0;
	if (count_arguments(arguments) == 1)
	{
		if (ft_is_real_digit(arguments[0]) == -1)
		{
			return (write(2, "bash: exit: numeric argument required\n", 38),
				write_temp_file(TMP_FILES, 2), 1);
		}
		else
		{
			n = ft_atoi(arguments[0]);
			if (n == 0)
				return (write_temp_file(TMP_FILES, 0), 1);
			else if (n == -1)
				return (write_temp_file(TMP_FILES, 255), 1);
			else if (n < -1)
				return (n = n + 256, write_temp_file(TMP_FILES, n), 1);
			else
				return (write_temp_file(TMP_FILES, (ft_atoi(arguments[0])
							% 256)), 1);
		}
	}
	return (0);
}
