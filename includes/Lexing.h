//
// Created by umbra on 9/16/24.
//

#ifndef MINISHELL_42_LEXING_H
#define MINISHELL_42_LEXING_H

# include <stdlib.h>
# include <stdio.h>

typedef struct	s_token
{
	char		*kind;
	char		*value;
}				t_token;

char	**ft_lexing_split();

#endif //MINISHELL_42_LEXING_H
