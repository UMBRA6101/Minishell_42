/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:51:18 by thomas            #+#    #+#             */
/*   Updated: 2024/01/15 14:32:35 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	who_print(va_list args, char flag)
{
	int	len;

	len = 0;
	if (flag == 's')
		len = ft_printstr(args);
	else if (flag == 'c')
		len = ft_printchar(args);
	else if (flag == 'p')
		len = ft_printptr(args);
	else if (flag == 'd')
		len = ft_printnum(args);
	else if (flag == 'i')
		len = ft_print_base_10(args);
	else if (flag == 'u')
		len = ft_printunsigned(args);
	else if (flag == 'x')
		len = ft_printhex(args);
	else if (flag == 'X')
		len = ft_printhex_maj(args);
	else if (flag == '%')
		len = ft_printpourcent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		out;
	int		itr_str;
	va_list	args;

	itr_str = 0;
	out = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[itr_str] != '\0')
	{
		if (str[itr_str] && !is_flag(str[itr_str], str[itr_str + 1]))
		{
			write(1, &str[itr_str], 1);
			out++;
		}
		if (is_flag(str[itr_str], str[itr_str + 1]))
		{
			out += who_print(args, str[itr_str + 1]);
			itr_str++;
		}
		itr_str++;
	}
	va_end(args);
	return (out);
}
