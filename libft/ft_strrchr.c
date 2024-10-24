/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:40:03 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/16 18:15:16 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*sexy;

	i = 0;
	sexy = s;
	while (sexy[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (sexy[i] == (unsigned char)c)
		{
			return (((char *)sexy) + i);
		}
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
// 	const char * s = "tes trop beau";
// 	int c = 't';
// 	printf("%s", ft_strrchr(s, c));
// }