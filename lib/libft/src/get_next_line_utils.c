/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:19:26 by thodos-s          #+#    #+#             */
/*   Updated: 2024/03/09 03:23:25 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	extract_line(char **line, char *buff)
{
	int	itr;

	if (!buff || buff[0] == '\0')
		return ;
	itr = 0;
	while (buff[itr] != '\0' && buff[itr] != '\n')
		itr++;
	if (buff[itr] == '\n')
		itr++;
	*line = ft_calloc(sizeof(char), (itr + 2));
	itr = 0;
	while (buff[itr] != '\0')
	{
		(*line)[itr] = buff[itr];
		if (buff[itr] == '\n')
			break ;
		itr++;
	}
	itr++;
	(*line)[itr] = '\0';
}
