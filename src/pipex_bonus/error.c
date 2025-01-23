/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:26:25 by rafaria           #+#    #+#             */
/*   Updated: 2025/01/23 03:37:29 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/parsing_error.h"
#include "minishell.h"

void	print_parsing_error(t_erreur *err)
{
	if (err->error_code == -1)
		return ;
	err->exit_value = 2;
	if (err->error_code == STX_ALLOC)
	{
		ft_putendl_fd("Allocation failed", 2);
		return ;
	}
	ft_putstr_fd("bash: syntax error near unexpected token `", ERROR_FD);
	if (err->error_code == STX_NL)
		ft_putstr_fd("newline", ERROR_FD);
	else if (err->error_code == SYNTAX)
		ft_putchar_fd(err->c, ERROR_FD);
	else if (err->error_code == D_SYNTAX)
	{
		ft_putchar_fd(err->c, ERROR_FD);
		ft_putchar_fd(err->c, ERROR_FD);
	}
	ft_putstr_fd("'\n", ERROR_FD);
}

void	display_error(char *cmd, char *mess, char **args,
		int variable)
{
	if (errno == ENOENT)
		handle_enoent_error(cmd, args, variable);
	else if (errno == EISDIR)
		handle_eisdir_error(cmd, args, variable);
	else if (errno == ENOTDIR)
		handle_enotdir_error(cmd, mess, args, variable);
	else if (errno == EACCES)
		handle_eacces_error(cmd, mess, args, variable);
	else if (ft_strcmp(mess, "cmd not found") == 0)
		handle_command_not_found(cmd, variable);
	else if (errno == ELOOP)
		handle_eloop_error(cmd, args, variable);
	else if (errno == ENAMETOOLONG)
		handle_enametoolong_error(cmd, args, variable);
}

void	display_args(char **args)
{
	int		fd[2];
	char	buffer[10000];
	size_t	bytes_read;
	int		i;

	pipe(fd);
	i = 0;
	if (args == NULL)
		return ;
	while (args[i] != NULL)
	{
		write(fd[1], args[i], ft_strlen(args[i]));
		i++;
	}
	bytes_read = read(fd[0], buffer, sizeof(buffer));
	write(2, buffer, bytes_read);
	close(fd[0]);
	close(fd[1]);
}

void	free_command(char **cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}
