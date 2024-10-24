/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:31:44 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/16 15:13:20 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t		i;
	char		*dest;
	const char	*src;

	dest = destination;
	src = source;
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*yuka;
	const char	*what;

	yuka = dest;
	what = src;
	if (yuka == 0 || what == 0)
		return (yuka);
	if (what == yuka)
		return (yuka);
	if (what > yuka)
	{
		yuka = ft_memcpy(yuka, what, n);
	}
	else
	{
		while (n > 0)
		{
			n--;
			yuka[n] = what[n];
		}
	}
	return (dest);
}

// #include <memory.h>
// #include <string.h>
// #include <stdio.h>

// char str1[7] = "aabbcc";
// char str2[7] = "zzzzzz";

// int main(void)
// {
//    printf( "The string: %s\n", str1 );
//    ft_memmove( str1 + 2, str1 + 1, 4 );
//    printf( "New string: %s\n", str1 );

// }