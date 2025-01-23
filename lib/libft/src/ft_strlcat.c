/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:46:54 by thomas            #+#    #+#             */
/*   Updated: 2023/11/17 18:01:42 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	k;

	if (size == 0)
		return (ft_strlen(src));
	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (size + src_len);
	k = 0;
	while (k < size - dest_len - 1 && src[k])
	{
		dest[dest_len + k] = src[k];
		k++;
	}
	dest[dest_len + k] = '\0';
	return (src_len + dest_len);
}
