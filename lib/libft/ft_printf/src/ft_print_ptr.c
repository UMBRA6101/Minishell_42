/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:27:23 by thomas            #+#    #+#             */
/*   Updated: 2024/01/15 14:32:14 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_size(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static char	*transfo_ptr(unsigned long ptr)
{
	int		len;
	char	*out;

	len = 0;
	out = NULL;
	len = find_size(ptr);
	out = ft_calloc(sizeof(char), len + 1);
	len--;
	while (ptr != 0)
	{
		if ((ptr % 16) < 10)
			out[len] = (ptr % 16) + 48;
		else
			out[len] = (ptr % 16) + 87;
		ptr /= 16;
		len--;
	}
	return (out);
}

int	ft_printptr(va_list args)
{
	unsigned long		ptr_val;
	char				*out;
	int					len;

	len = 0;
	ptr_val = 0;
	out = NULL;
	ptr_val = va_arg(args, unsigned long);
	if (!ptr_val)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	out = transfo_ptr(ptr_val);
	len = ft_strlen(out);
	ft_putstr(out);
	free(out);
	out = NULL;
	return (len + 2);
}
