/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 05:11:20 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/15 17:49:02 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	itr_str;

	if (!str)
		return ;
	itr_str = 0;
	while (str[itr_str] != '\0')
	{
		ft_putchar_fd(str[itr_str], fd);
		itr_str++;
	}
}
