/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base_10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:52:54 by thodos-s          #+#    #+#             */
/*   Updated: 2024/01/15 13:47:22 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_size(int src)
{
	int	size;

	size = 0;
	if (src == 0)
		return (1);
	if (src < 0)
	{
		src *= (-1);
		size++;
	}
	while (src >= 1)
	{
		src /= 10;
		size++;
	}
	return (size);
}

static char	*to_10(int nbr, char *out)
{
	int	size;
	int	is_neg;

	is_neg = 0;
	size = 0;
	size = find_size(nbr);
	out = ft_calloc(sizeof(char), size + 1);
	size--;
	if (nbr < 0)
	{
		is_neg = 1;
		nbr *= -1;
	}
	while (size >= 0)
	{
		out[size] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	if (is_neg == 1)
		out[0] = '-';
	return (out);
}

int	ft_print_base_10(va_list args)
{
	char	*out;
	int		nbr;
	int		len;

	out = NULL;
	nbr = va_arg(args, int);
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	out = to_10(nbr, out);
	ft_putstr(out);
	len = ft_strlen(out);
	free(out);
	return (len);
}
