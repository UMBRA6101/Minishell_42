/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:11:21 by thomas            #+#    #+#             */
/*   Updated: 2024/01/11 15:25:49 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_maj(va_list args)
{
	char	*out;
	int		num_hex;
	int		len;

	out = NULL;
	num_hex = va_arg(args, int);
	out = transfo_hex((unsigned long long)num_hex, 55);
	out = upper_case(out);
	ft_putstr(out);
	len = ft_strlen(out);
	free(out);
	return (len);
}
