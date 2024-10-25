/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:10:50 by raphox            #+#    #+#             */
/*   Updated: 2024/10/24 15:26:04 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include "stdbool.h"

typedef struct s_data_rule
{
    char *command;
    char *options;
    const char **arguments;
    int nbr_args;
    char *dir_path;
    char *out;
    bool pipe;

} t_data_rule;


// PIPEX BONUS . C ---------------------------------------------------------------------------------------------

void wait_for_children(void);
void execute(t_data_rule data, char **envp);
void free_command(char **cmd);
void first_process(t_data_rule data, char **env, int *input_fd, int *p_fd, int is_last_cmd);
void second_process(int *input_fd, int *p_fd, int is_last_cmd);
void do_pipe(t_data_rule data, char **env, int *input_fd, int is_last_cmd);
int pipex(t_data_rule *data, int num_commands, char **envp);
void exit_with_error(const char *msg);


// BUILD COMMAND . C ---------------------------------------------------------------------------------------------

char    **build_command(t_data_rule data);
int    count_options(char *options, char ***split_command);
char    **allocate_command(int options_count, int nbr_args);
int    copy_command_to_cmd(char **cmd, char *command);
int    copy_options_to_cmd(char **cmd, char **split_command, int *i, int j);
int    copy_arguments_to_cmd(char **cmd, const char **arguments, int *i, int nbr_args);

// TOOLS . C ---------------------------------------------------------------------------------------------

void error(int i, char *str);
void    free_command(char **cmd);
void wait_for_children(void);

// SPLIT . C ---------------------------------------------------------------------------------------------

char	**ft_split(char *s, char c);


#endif