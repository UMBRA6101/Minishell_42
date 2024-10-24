/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:56:56 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/23 18:27:06 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && (i + j) < len && little[j])
			j++;
		if (!little[j])
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (0);
}

// #include <bsd/string.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	*s1 = "bonjour comment ca va";
// 	const char	*s2 = "comment";
// 	size_t res = 4;

// 	printf("%s\n", ft_strnstr(s1, s2, res));
// 	printf("%s", strnstr(s1, s2, res));
// 	printf("\n");

// 		char haystack[30] = "aaabcabcd";

// 	#include <assert.h>
// 	assert ( ft_strnstr(haystack, "a", __INT_MAX__) == haystack );

// }
