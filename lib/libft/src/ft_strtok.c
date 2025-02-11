/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 05:56:26 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/23 05:58:50 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char *sep)
{
	int			size_out;
	static char	*path;
	char		*out;

	if (str != NULL)
		path = str;
	if (path == NULL)
		return (NULL);
	out = path;
	size_out = ft_strcspn(out, sep);
	if (size_out != ft_strlen(path))
	{
		path[size_out - 1] = '\0';
		path += size_out;
	}
	else
		path = NULL;
	return (out);
}
