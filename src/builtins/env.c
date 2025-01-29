/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:53:16 by raphox            #+#    #+#             */
/*   Updated: 2025/01/22 20:04:02 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(char **envv)
{
	int		fd[2];
	char	buffer[10000];
	size_t	bytes_read;
	int		i;

	pipe(fd);
	i = 0;
	while (envv[i] != NULL)
	{
		write(fd[1], envv[i], ft_strlen(envv[i]));
		write(fd[1], "\n", 1);
		i++;
	}
	bytes_read = read(fd[0], buffer, sizeof(buffer));
	write(1, buffer, bytes_read);
	close(fd[0]);
	close(fd[1]);
	write_temp_file(TMP_FILES, 0);
}
