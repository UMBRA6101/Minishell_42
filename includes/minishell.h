/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 05:53:31 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/27 13:00:15 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Parsing.h"
# include "libft.h"
# include "parsing_error.h"
# include "stdbool.h"
# include "struct_shell.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define PROMPT "Minishell-> "
# define TMP_FILES "/tmp/minishell_tmp"

extern pid_t	g_pid;

int				check_export_before_equal(char *args);

int				check_lign_in_envv(int limiter, char *argument,
					char *ligne_envv);
int				check_if_in_envv(char *argument, char **envv);

char			**allocate_new_env_to_modify_variable(int pin, char **env,
					char *arguments);
char			**init_minimal_env(void);

int				tchoupi(t_data_rule *data, t_struc_process *struct_exec,
					t_erreur *err);
void			truc(t_data_rule *data, int i, t_struc_process *struct_exec,
					t_erreur *err);

void			handle_enoent_error(char *cmd, char **args, int variable);
void			handle_eisdir_error(char *cmd, char **args, int variable);
void			handle_enotdir_error(char *cmd, char *mess, char **args,
					int variable);
void			handle_eacces_error(char *cmd, char *mess, char **args,
					int variable);
void			handle_command_not_found(char *cmd, int variable);

void			display_error_message(char *cmd, char *mess, int errno_code,
					char **args);
void			handle_eloop_error(char *cmd, char **args, int variable);
void			handle_enametoolong_error(char *cmd, char **args, int variable);

void			signal_treatment(int sig);

int				built_exit_2(char **arguments);

void			check_cmd_in_cmd(char **pathname, t_data_rule *struct_data,
					t_data_rule data, t_struc_process *struct_exec);

int				check_exit(t_data_rule *struct_data, t_data_rule data,
					t_struc_process struct_exec, t_erreur *err);

int				check_builtins_before_pipe(t_data_rule *struct_data,
					t_data_rule data, t_struc_process struct_exec,
					t_erreur *err);

int				handle_builtins(t_data_rule *data, t_data_rule data_command,
					t_struc_process struct_exec, t_erreur *err);
void			init_struct_exec(t_struc_process *struct_exec, int *input_fd,
					int *tab_heredoc, int index);

/* MAIN */
int				count_data(t_data_rule *data);
char			**ft_strdup_env(char **envp);

int				is_directory(const char *path);

int				check_if_h_is_find(char *str);

int				give_latest_heredoc(t_data_rule data);

int				check_slash(char *cmd);

/* PIPEX */

void			free_execution_process(t_data_rule *struct_data,
					t_struc_process struct_exec);

void			check_redirections_in_cmd(t_data_rule *struct_data,
					t_data_rule data, t_struc_process struct_exec);

void			write_temp_file(const char *filename, int value);
char			*read_temp_file(const char *filename);

int				ft_strcmp(char *s1, char *s2);

char			**pipex(t_data_rule *data, t_erreur *err, int num_commands,
					char **envv);
void			do_pipe(t_data_rule *struct_data, t_data_rule data,
					t_struc_process struct_exec);
void			execution_process(t_data_rule *struct_data, t_data_rule data,
					t_struc_process struct_exec);
void			second_process(t_struc_process struct_exec);
void			execute(t_data_rule *struct_data, t_data_rule data,
					t_struc_process struct_exec);

int				ask_tmp_files(void);

void			free_heredoc(int *tab_heredoc, int num_commands);
void			exit_with_error(char *msg);
void			free_command(char **cmd);

/* REAL BUILDER COMMAND */

char			**build_execution(t_data_rule data);
char			*build_command(char *command);
char			**allocate_command(char *command, char **split_command,
					int option_count, int nbr_args);
int				count_options(char **options, int *option_count);
void			free_command_array(char **cmd);

int				append_elements(char **cmd, char **elements, int index,
					char *type);

/* TOOLS */
int				handle_heredoc(char *delimiter);
int				*prepare_heredocs(t_data_rule *data, int num_commands);
int				handle_redirection(t_data_rule data);
int				handle_entry_redirections(t_data_rule data, char oper,
					char *input);
int				handle_exit_redirections(t_data_rule data, char oper,
					char *output);
char			*find_path(char *cmd_brut, char *cmd, char **envv);
void			wait_for_children(void);

void			is_tmpfile_90(int pipe_lecutre, int pipe_ecriture);
void			ctrl_d(char *line, char *delimiter);

/* CHECK REDIRECTIONS */

int				check_redirections(t_data_rule data);
int				chk_entry(char oper, char *input);
int				chk_exit(char oper, char *output);

int				check_whole_exit_redirections(t_data_rule data);
int				check_whole_entry_redirections(t_data_rule data);

/* SPLIT */

char			**ft_my_split(char *s, char c);

/* BUILTING */
char			**exec_builtins(t_data_rule struc, char **envv);
int				check_if_in_builtins(t_data_rule struc);

/* CD GOOOD */

int				count_arguments(char **tab);

void			handle_cd_errors(char **arguments);

void			update_env(char **envp, char *old_pwd, char *new_pwd);

char			**cd(char *command, char **args, char **envp);

char			*resolve_path(const char *cwd, const char *relative_path);

void			parse_segments(const char *path, char **segments,
					int *segment_count);
void			handle_special_segments(char *temp, char **segments,
					int *segment_count, int start);

char			*custom_realpath(const char *path);
/* Echo GOOD */
void			echo(char *command, char **option, char **arguments);
void			display_echo(char *command, char **option, char **arguments,
					char *result);
int				display_echo_2(char *command, char **option, char **arguments,
					char *result);

/* Env GOOD */
void			display_env(char **envp);

/* Export */
char			**export(char *command, char **arguments, char **envv);
char			**cmd_export(char *arguments, char **env);
// ajouter variable a l env 2 ou+
char			**allocate_new_env_to_add_variable(char **env, char *arguments);
int				size_env(char **env, char **new_env);

/* Pwd GOOD */
void			pwd(char *command, char **envv); // recopie pwd

/* Unset */
char			**unset(char **arguments, char **envp);
char			**cmd_unset(char **env, char *var); // retirer variable de l env
int				check_var(char *str);

/* EXIT GOOD */
int				built_exit(char **arguments);
int				ft_is_real_digit(char *str);

/* ERROR */
void			display_error(char *cmd, char *mess, char **args, int variable);
void			display_args(char **args);

void			free_env(char **env);
void			handle_free(char **envp);
void			free_command(char **cmd);

/* TOOLS BUILT */

void			swap(char **a, char **b);
int				find_in_envv(char **envv, char *var);
void			bubble_sort(char **envp);
void			display_x_variables(char **result);
int				compare_strings(char *str1, char *str2);

char			**ft_strdup_env(char **envp);
char			**copy_the_env(char **envp);

/* FREE */
void			free_all(t_info **info, char *rule, int ext);

#endif
