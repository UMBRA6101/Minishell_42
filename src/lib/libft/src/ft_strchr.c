/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:52:59 by thomas            #+#    #+#             */
/*   Updated: 2023/11/17 13:32:43 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *src, int tofind)
{
	int		itr;
	char	c;

	c = (char)tofind;
	itr = 0;
	while (src[itr])
	{
		if (src[itr] == c)
			return ((char *) &src[itr]);
		itr++;
	}
	if (src[itr] == c)
		return ((char *) &src[itr]);
	return (NULL);
}
