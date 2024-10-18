/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:10:50 by raphox            #+#    #+#             */
/*   Updated: 2024/10/18 10:22:59 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

#include "../includes/minishell.h"
#include "../includes/libft.h"

void	error(int i, char *str);
int		main(int ac, char **av, char **envp);
void	ft_close(int *fd);

void	do_pipe(char *cmd, char **env);
int	open_file(char *file, int in_or_out);


void	execute(char *string, char **envp);
char	*find_path(char *cmd, char **envp);
char	**ft_split_pipex(char *s, char c);
void	final_execute(char *path, char **cmd, char **envp);

#endif