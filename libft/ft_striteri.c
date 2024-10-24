/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:33:07 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/20 17:32:10 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

char	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	i2;

	i2 = 0;
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		while (i2 < i)
		{
			(f)(i2, s);
			i2++;
			s++;
		}
		return (i2);
	}
	return (0);
}

// void iter(unsigned int i, char *s) 
// {
// 	*s += i;
// }

// #include <stdlib.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char s[] = "0000000000";
// 	printf("%d", ft_striteri(s, iter));
// 	write(1, "\n", 1);
// 	return (0);
// }