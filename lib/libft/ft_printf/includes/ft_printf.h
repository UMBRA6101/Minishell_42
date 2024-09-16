/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:34:38 by thomas            #+#    #+#             */
/*   Updated: 2024/01/11 15:47:28 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define SIZE_BASE_HEX 16

typedef struct s_flag
{
	int		(*ft)(va_list args);
	char	nom;
}		t_flag;

int		ft_printf(const char *str, ...);
int		who_print(va_list args, char flag);
int		is_flag(char indic, char flag);
char	*upper_case(char *str);
char	*transfo_hex(unsigned int num, int arg);
int		count_size(long nbr);
int		ft_printhex_maj(va_list args);
void	ft_putstr(char *str);
int		ft_printstr(va_list args);
int		ft_printchar(va_list args);
int		ft_printnum(va_list args);
int		ft_printhex(va_list args);
int		ft_printptr(va_list args);
int		ft_print_base_10(va_list args);
int		ft_printunsigned(va_list args);
int		ft_printpourcent(void);

#endif
