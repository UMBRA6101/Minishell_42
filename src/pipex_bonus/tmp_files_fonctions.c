/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_files_fonctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:56:53 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/23 02:50:53 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ask_tmp_files(void)
{
	char	*content;
	int		ko;

	ko = 0;
	content = read_temp_file(TMP_FILES);
	if (content == NULL)
	{
		write(2, "Error content", 13);
		return (0);
	}
	ko = ft_atoi(content);
	if (content != NULL)
	{
		free(content);
	}
	return (ko);
}

void	write_temp_file(const char *filename, int value)
{
	int		fd;
	char	*buffer;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	buffer = ft_itoa(value);
	if (write(fd, buffer, ft_strlen(buffer)) == -1)
	{
		perror("write");
		close(fd);
		exit(1);
	}
	free(buffer);
	close(fd);
}

char	*read_temp_file(const char *filename)
{
	int		fd;
	char	*content;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	content = malloc(99);
	if (content == NULL)
		return (perror("malloc"), close(fd), NULL);
	bytes_read = read(fd, content, 99);
	if (bytes_read == -1)
		return (perror("read"), free(content), close(fd), NULL);
	content[bytes_read] = '\0';
	close(fd);
	return (content);
}
