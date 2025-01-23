/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 05:57:33 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/23 05:57:37 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcspn(const char *str, const char *sep)
{
	int	itr_str;
	int	itr_sep;

	itr_str = 0;
	while (str[itr_str])
	{
		itr_sep = 0;
		while (str[itr_str] == sep[itr_sep] && str[itr_str])
		{
			itr_str++;
			itr_sep++;
			if (sep[itr_sep] == '\0')
				return (itr_str);
		}
		itr_str++;
	}
	return (itr_str);
}
