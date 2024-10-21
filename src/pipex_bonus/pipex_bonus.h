/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:10:50 by raphox            #+#    #+#             */
/*   Updated: 2024/10/19 16:31:11 by raphox           ###   ########.fr       */
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


int pipex(int ac, char **av, char **envp);
void do_pipe(char *cmd, char **env, int *input_fd, int is_last_cmd);
void handle_parent_process(int *input_fd, int *p_fd, int is_last_cmd);
void wait_for_children(void);
void handle_child_process(char *cmd, char **env, int *input_fd, int *p_fd, int is_last_cmd);
void close_pipes(int *pipes);


void	error(int i, char *str);
void	execute(char *string, char **envp);
char	*find_path(char *cmd, char **envp);
char	**ft_split_pipex(char *s, char c);
void	final_execute(char *path, char **cmd, char **envp);

#endif