/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:26:00 by thomas            #+#    #+#             */
/*   Updated: 2024/01/17 09:26:11 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char indic, char flag)
{
	if (indic != '%')
		return (0);
	if (flag == 'c' || flag == 's' || flag == 'd' || flag == 'x' || flag == 'X'
		|| flag == 'p' || flag == 'i' || flag == 'u' || flag == '%')
		return (1);
	return (0);
}

static int	find_size(unsigned int num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

char	*transfo_hex(unsigned int num, int arg)
{
	char	*buff;
	int		size_buff;

	size_buff = find_size(num);
	buff = ft_calloc(sizeof(char), size_buff + 1);
	size_buff--;
	if (num == 0)
		buff[0] = '0';
	while (num != 0)
	{
		if ((num % 16) < 10)
			buff[size_buff] = (num % 16) + 48;
		else
			buff[size_buff] = (num % 16) + arg;
		num = num / 16;
		size_buff--;
	}
	return (buff);
}

char	*upper_case(char *str)
{
	int	itr;

	itr = 0;
	if (str == NULL)
		return (NULL);
	while (str[itr] && str[itr] != '\0')
	{
		if (str[itr] >= 'a' && str[itr] <= 'z')
			str[itr] -= 32;
		itr++;
	}
	return (str);
}
