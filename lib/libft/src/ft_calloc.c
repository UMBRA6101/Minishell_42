/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:41:49 by thodos-s          #+#    #+#             */
/*   Updated: 2023/12/03 17:09:07 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*temp;

	if (elementCount == 0 || elementSize == 0)
	{
		elementCount = 1;
		elementSize = 1;
	}
//	if (elementSize > SIZE_MAX / elementCount)
//		return (NULL);
	temp = malloc(elementCount * elementSize);
	if (!temp)
		return (NULL);
	ft_bzero(temp, elementCount * elementSize);
	return ((void *)temp);
}
