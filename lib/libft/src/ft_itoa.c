/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:50:10 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:44:15 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_size(long nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		nbr *= (-1);
		size = 1;
	}
	if (nbr == 0)
		size = 1;
	else
	{
		while (nbr > 0)
		{
			nbr /= 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		tab_size;
	int		is_neg;
	long	nbr;
	char	*tab_out;

	nbr = n;
	tab_size = count_size(nbr);
	tab_out = malloc(sizeof(char) * tab_size + 1);
	if (!tab_out)
		return (0);
	is_neg = 0;
	if (nbr < 0)
	{
		nbr *= (-1);
		tab_out[0] = '-';
		is_neg = 1;
	}
	tab_out[tab_size] = '\0';
	while (--tab_size >= is_neg)
	{
		tab_out[tab_size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (tab_out);
}
