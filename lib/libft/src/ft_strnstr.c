/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:58:57 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:41:48 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!little[0])
		return ((char *)big);
	else if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + k] == little[k] && i + k < len && big[i + k])
		{
			k++;
			if (little[k] == 0)
				return ((char *)big + i);
		}
		i++;
		k = 0;
	}
	return (NULL);
}
