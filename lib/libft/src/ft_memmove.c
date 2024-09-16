/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:02:50 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:22:44 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;
	size_t			k;

	k = 0;
	if (!dest && !src)
		return (NULL);
	tmp_src = (unsigned char *)src;
	tmp_dest = (unsigned char *)dest;
	if (tmp_dest > tmp_src)
		while (len-- > 0)
			tmp_dest[len] = tmp_src[len];
	else
	{
		while (k < len)
		{
			tmp_dest[k] = tmp_src[k];
			k++;
		}
	}
	return (dest);
}
