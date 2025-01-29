/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:14:46 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/28 14:50:35 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] > 8 && str[i] < 14)))
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+' && sign != -1)
		i++;
	number = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i++] - 48;
	}
	return (number * sign);
}
