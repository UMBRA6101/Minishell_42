/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:42:48 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/22 21:42:53 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERROR_H
# define PARSING_ERROR_H

# define ERR_SYX "bash: syntax error near"
# define ERROR_FD 2

typedef struct s_erreur
{
	int		sw;
	int		error_code;
	int		exit_value;
	char	c;
}			t_erreur;

void		print_parsing_error(t_erreur *err);

enum
{
	STX_NL,
	SYNTAX,
	D_SYNTAX,
	STX_ALLOC
};

#endif
