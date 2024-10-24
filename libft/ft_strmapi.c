/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:29 by rafaria           #+#    #+#             */
/*   Updated: 2023/11/23 18:24:30 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*blyat;
	int		taille;

	taille = ft_strlen(s) + 1;
	i = 0;
	blyat = malloc(sizeof(char) * (taille));
	if (blyat == NULL)
		return (NULL);
	while (s[i])
	{
		blyat[i] = (*f)(i, s[i]);
		i++;
	}
	blyat[i] = '\0';
	return (blyat);
}

// int	main(void)
// {
// 	const char s[] = "abcdef";
// 	printf("%s", ft_strmapi(s, suka));
// }