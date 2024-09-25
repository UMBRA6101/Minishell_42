//
// Created by umbra on 9/16/24.
//

#ifndef MINISHELL_42_LEXING_H
#define MINISHELL_42_LEXING_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_token
{
	char	sep;
	int 	state;
	int		nb_word;
	int 	len_word;
}				t_token;

typedef struct	s_split
{
	char 	sep;
	int		len_word;
	char 	*words;
	int 	state;
}				t_split;

char	*delete_space(char *command);
int	nb_words(char *command);
int	r_value(char *command, int i, t_token *token);
int	is_oper(char c);
int	ft_isspace(char c);
int	state_finish(t_token *token);
int	ft_isend(const char c);
int	state_in_view(const char *command, const int i);
int	len_of_word(char *command, int i);

enum {RESET, SPACES, OPER, QUOTE, D_QUOTE};

#endif //MINISHELL_42_LEXING_H
