/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:02:52 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/23 18:23:19 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*sup1;
	char	*sup2;
	int		diff;

	i = 0;
	sup1 = (char *)dest;
	sup2 = (char *)src;
	diff = 0;
	while (i < n)
	{
		diff = sup2[i] - sup1[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

// #include <stddef.h>
// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char string1[] = {10, 20, 30, -41};
//     char string2[] = {10, 20, 30, -40};
//     size_t bee = 100;

//     printf("%d",(ft_memcmp(string1, string2, bee)));
// 	printf("\n");
// 	printf("%d",(memcmp(string1, string2, bee)));
// }