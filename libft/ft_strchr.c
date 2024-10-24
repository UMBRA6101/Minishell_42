/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:03:37 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/16 17:25:06 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*sexy;

	i = 0;
	sexy = s;
	while (sexy[i])
	{
		if (sexy[i] == (unsigned char)c)
		{
			return (((char *)sexy) + i);
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	*s = "tripouille";
// 	int			c;

// 	c = 'a';
// 	printf("%s", ft_strchr(s, 9));
// }
