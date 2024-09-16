/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 04:13:57 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:21:19 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab_out;
	int		itr_tab;

	if (!s)
		return (NULL);
	tab_out = 0;
	tab_out = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!tab_out)
		return (NULL);
	itr_tab = 0;
	while (s[itr_tab] != 0)
	{
		tab_out[itr_tab] = (*f)(itr_tab, s[itr_tab]);
		itr_tab++;
	}
	tab_out[itr_tab] = '\0';
	return (tab_out);
}
