/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:07:04 by thomas            #+#    #+#             */
/*   Updated: 2023/11/15 12:11:14 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int tofind)
{
	int	tab_len;

	tab_len = ft_strlen((char *)src);
	while (tab_len >= 0)
	{
		if (src[tab_len] == (char)tofind)
			return ((char *)(src + tab_len));
		tab_len--;
	}
	return (NULL);
}
