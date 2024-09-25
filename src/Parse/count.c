//
// Created by umbra on 9/23/24.
//

# include "Parsing.h"

int	state_in_view(const char *command, const int i)
{
	if (command[i] == '\"')
		return (D_QUOTE);
	if (command[i] == '\'')
		return (QUOTE);
	if (is_oper(command[i]))
		return (OPER);
	return (SPACES);
}