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
	char		*kind;
	char		*value;
}				t_token;

char	**ft_lexing_split();
// je suis la 'comment ca vas' aujourd'hui
#endif //MINISHELL_42_LEXING_H
