/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:38:19 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/16 18:27:46 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] != '\0' && i < (n -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

// #include <stddef.h>
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	size_t	i;
// 	char	destination[] = "Salu";
// 	char	s[] = "bonjourRRRRRRR";

// 	i = 15;
// 	printf("%ld", ft_strlcpy(destination, s, i));
// 	printf("\n");
// }

// #include<stddef.h>
// #include<stddef.h>
// size_t    ft_strlcpy(char *dest, char *src, size_t dstsize)
// {
//     int    i;
//     i = 0;

//     while (src[i] != '\0' || i < (dstsize - 1))
//     {
//         dest[i] = src[i];
//         i++;
//     }
//     dest[i] = '\0';
//     i = 0;
//     while (dest[i])
//         i++;
//     return (((size_t)i));
// }