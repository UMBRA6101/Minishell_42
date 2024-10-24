/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:18:40 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/23 18:23:13 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n t unsigned long int
#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;
	unsigned char	ch;

	i = 0;
	str = (char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}

// #include <stddef.h>
// #include<stdio.h>

// int main()
// {
// 	char string[] = "tes archi bizarre";
// 	int i = 'i';
// 	size_t bee = 9;

// 	printf("%s",(unsigned char *)(ft_memchr(string, i, bee)));
// }