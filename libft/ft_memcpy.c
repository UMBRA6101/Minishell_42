/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:27:33 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/16 14:58:22 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*yuka;
	const char	*zub;

	yuka = dest;
	zub = src;
	i = 0;
	while (i < n)
	{
		yuka[i] = zub[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {

//     int array [] = { 54, 85, 20, 62, 21 };
//     int * copy = NULL;
//     int length = sizeof( int ) * 5;

//     /* Memory allocation and copy */
//     copy = (int *) malloc( length );
//     ft_memcpy( copy, array, length );
// 			printf( "\n" );

//     /* Display the copied values */
//     for( length=0; length<5; length++ ) {
//         printf( "%d ", copy[ length ] );
//     }
//     printf( "\n" );

//     free( copy );

//     return (EXIT_SUCCESS);
// }