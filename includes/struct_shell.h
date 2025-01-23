/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_shell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:44:34 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/23 04:03:02 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SHELL_H
# define STRUCT_SHELL_H

# include "parsing_error.h"
# include "stdbool.h"

typedef struct s_data_rule
{
	char				*command;
	char				**options;
	char				**arguments;
	int					nbr_args;
	char				*dir_path;
	char				**out;
	char				*input;
	int					nb_rdir;
	int					nb_opt;
	char				*oper;
	bool				pipe;
	int					nb_command;
}						t_data_rule;

typedef struct s_struc_process
{
	char				**cmd;
	char				**env;
	int					*input_fd;
	int					is_last_command;
	int					num_commands;
	int					fd_heredoc;
	int					*tab_heredoc;
	int					*p_fd;

}						t_struc_process;

typedef struct s_info
{
	struct s_data_rule	*cmd;
	struct s_var		*var;
	char				**envv;
	struct s_erreur		*err;
	bool				sq;
}						t_info;

#endif
