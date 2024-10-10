//
// Created by umbra on 10/9/24.
//
#include "../includes/libft.h"
#include "../includes/parsing_error.h"

void	print_parsing_error(t_erreur err)
{
	if (err.error_code == -1)
		return ;
	if (err.error_code == STX_ALLOC)
	{
		ft_putendl_fd("Allocation failed", 2);
		return ;
	}
	ft_putstr_fd("bash: syntax error near\nunexpected token `", ERROR_FD);
	if (err.error_code == STX_QUOTE)
		ft_putstr_fd("newline", ERROR_FD);
	else if (err.error_code == SYNTAX)
		ft_putchar_fd(err.c, 2);
	ft_putstr_fd("'\n", 2);
}