/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:46:04 by raphox            #+#    #+#             */
/*   Updated: 2025/01/22 19:50:14 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirections(t_data_rule data)
{
	int	i;

	i = 0;
	if (data.oper != NULL && data.oper[i] != 0)
		i = 0;
	else
		return (0);
	while (data.out[i] != NULL)
	{
		if (data.oper[i] == '<' && chk_entry(data.oper[i], data.input) == -1)
		{
			return (-1);
		}
		else if ((data.oper[i] == '>' || data.oper[i] == 'r')
			&& chk_exit(data.oper[i], data.out[i]) == -1)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_whole_exit_redirections(t_data_rule data)
{
	int	i;

	i = 0;
	if (data.oper != NULL && data.oper[i] != 0)
		i = 0;
	else
		return (0);
	while (data.oper[i])
	{
		if (chk_exit(data.oper[i], data.out[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	chk_exit(char oper, char *output)
{
	int	fd;

	if (oper == '>')
	{
		fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			write_temp_file(TMP_FILES, 1);
			return (-1);
		}
		close(fd);
	}
	else if (oper == 'r')
	{
		fd = open(output, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (fd == -1)
		{
			write_temp_file(TMP_FILES, 1);
			return (-1);
		}
		close(fd);
	}
	return (0);
}

int	check_whole_entry_redirections(t_data_rule data)
{
	int	i;

	i = 0;
	if (data.oper != NULL)
		i = 0;
	else
		return (0);
	while (data.oper[i])
	{
		if (chk_entry(data.oper[i], data.out[i]) == -1)
		{
			write_temp_file(TMP_FILES, 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	chk_entry(char oper, char *input)
{
	int	fd;

	if (oper == '<')
	{
		fd = open(input, O_RDONLY);
		if (fd == -1)
		{
			write_temp_file(TMP_FILES, 1);
			return (-1);
		}
		close(fd);
	}
	return (0);
}

// else if (data.oper[i] == 'h' && handle_heredoc(data.input) == -1)
// {
// 	return (-1);
// }

// int check_handle_heredoc(char *delimiter)
// {
//     char *line;
//     int   pipe_fds[2];

//     if (pipe(pipe_fds) == -1)
//     {
//         perror("Erreur lors de la création du pipe");
//     }
//     while (1)
//     {
//         line = readline("> ");
//         if (!line)
//         {
//             printf("CTRL D PRESSED \n");
// 			return (-1);
//         }
//         if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
//         {
//             free(line);
//             break ;
//         }
//         write(pipe_fds[1], line, ft_strlen(line));
//         write(pipe_fds[1], "\n", 1);
//         free(line);
//     }
//     close(pipe_fds[1]);
//     dup2(pipe_fds[0], STDIN_FILENO);
//     close(pipe_fds[0]);
// 	return (0);
// }
// if (arguments != NULL)
// {
// 	dir = opendir(arguments[0]);
// 	if (dir == NULL)
// 	{
// 		display_error("cd", NULL, errno, arguments);
// 		closedir(dir);
// 		return(envp);
// 	}
// }