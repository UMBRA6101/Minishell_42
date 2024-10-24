/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:03:49 by marvin            #+#    #+#             */
/*   Updated: 2023/11/23 18:22:54 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) < nmemb || (nmemb * size) < size)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
		tmp[i++] = 0;
	return (tmp);
}

// int	main(void)
// {
// 	size_t n = -4;
// 	size_t size = 4;
// 	printf("%p", ft_calloc(n, size));
// }
// int : min = -2147483648 ; max = 2147483647