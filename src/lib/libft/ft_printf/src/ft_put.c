/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:55:49 by thomas            #+#    #+#             */
/*   Updated: 2024/01/17 09:27:23 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	itr;

	itr = 0;
	if (!str)
		return ;
	while (str[itr] != '\0')
	{
		write(1, &str[itr], 1);
		itr++;
	}
}

int	ft_printstr(va_list args)
{
	char	*out;
	int		len;

	out = NULL;
	out = va_arg(args, char *);
	if (out == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr(out);
	len = ft_strlen(out);
	return (len);
}

int	ft_printchar(va_list args)
{
	char	*out;

	out = va_arg(args, char *);
	write(1, &out, 1);
	return (1);
}

int	ft_printnum(va_list args)
{
	char	*out;
	int		num;
	int		len;

	out = NULL;
	num = va_arg(args, int);
	out = ft_itoa(num);
	ft_putstr(out);
	len = ft_strlen(out);
	free(out);
	return (len);
}

int	ft_printhex(va_list args)
{
	char	*out;
	int		num_hex;
	int		len;

	out = NULL;
	num_hex = va_arg(args, int);
	out = transfo_hex((long long)num_hex, 87);
	ft_putstr(out);
	len = ft_strlen(out);
	free(out);
	out = NULL;
	return (len);
}
