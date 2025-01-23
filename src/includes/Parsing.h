/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:12:57 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/22 21:51:07 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "parsing_error.h"
# include "struct_shell.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_token
{
	char			sep;
	int				state;
	int				nb_word;
	int				len_word;
}					t_token;

typedef struct s_split
{
	char			sep;
	int				len_word;
	char			*word;
	bool			quote;
}					t_split;

int					add_arg_request(t_data_rule *request, t_split *split,
						const int nb_node);
int					add_command(t_data_rule *request, t_split *split);
int					add_rdir(t_data_rule *request, t_split *split);
int					add_pipe(t_data_rule *request, t_split *split,
						const int count_word);
int					add_opt_request(t_data_rule *request, t_split *split,
						const int nb_opt);
int					add_semicolon(t_split *split);
int					braquet_check(char *str, t_erreur *err);
bool				b_quote(char c);
int					check_rdir(char *buff, int len);
char				*delete_space(char *command);
char				*delete_inutile_quote(char *command);
int					dollard_exist(char *rqst, t_info **data, int *index);
void				dollard_env(char *rqst, int *index, char **str,
						t_info **data);
int					dollar_traitment(t_info **data, char **rqst);
int					empty_braquet(char *str);
int					ft_nbr_option(const t_split *split, const int nb_node);
int					ft_nb_rdir(t_split *split);
int					ft_isspace(char c);
int					ft_isend(const char c);
int					ft_occ(char *str, char c);
void				fill_conv_rdir(t_data_rule *request, const int rdir,
						const int itr_oper);
void				fill_rdir(t_data_rule *request, t_split *split, int itr,
						int itr_oper);
int					is_oper(char c);
int					is_rdir(char c);
void				quote_id(bool *sq, bool *dq, int *i, char c);
int					nb_words(char *command);
int					state_finish(t_token *token);
int					state_in_view(const char *command, const int i);
int					len_of_word(char *command, int i);
int					nb_command(t_split *split, int count_word);
int					node_finish(char *buff, int len);
int					occ_rdir(char *buff);
int					echo_test(t_data_rule *rqst, t_split *split, int nb_node);
int					trim_useless(char **str, t_erreur *err);
int					trim_space(char *str);
int					trim_useless(char **str, t_erreur *err);
int					request_count(t_split *split, int count_word);
struct s_data_rule	*parsing(t_info *data, char **rqst);
struct s_data_rule	*parsing_tree(t_split *split, const int count_word);
int					r_node(t_split *split, int i);
int					r_value(char *command, int i, t_token *token);
int					valid_braquet(char *str, int *b_left, int *b_right);
int					syntax_check(t_split *split, const int nb_word,
						struct s_erreur *err);
void				killer_request(struct s_data_rule *request);
void				killer_split(t_split *split, const int nb_word);

enum
{
	RESET,
	SPACES,
	OPER,
	QUOTE,
	D_QUOTE
};
enum
{
	OTHER,
	INPUT,
	D_INPUT,
	RDIR,
	D_RDIR,
	PIPE
};

#endif
