/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 04:45:21 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:23:17 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	itr_str;

	if (!s || !f)
		return ;
	itr_str = 0;
	while (s[itr_str] != '\0')
	{
		(*f)(itr_str, s + itr_str);
		itr_str++;
	}
}
