/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:14:05 by thodos-s          #+#    #+#             */
/*   Updated: 2024/01/15 14:23:55 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(va_list args)
{
	unsigned int	nbr;
	unsigned int	len;
	char			*out;

	nbr = va_arg(args, unsigned int);
	out = ft_itoa((long int)nbr);
	ft_putstr(out);
	len = ft_strlen(out);
	free(out);
	return (len);
}
