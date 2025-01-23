/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:14:57 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/10 16:48:24 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	tofind;
	size_t			i;

	i = 0;
	str = (unsigned char *) src;
	tofind = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == tofind)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
