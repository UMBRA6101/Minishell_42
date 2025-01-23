/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:16:39 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/15 16:13:20 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_it(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*chao(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (is_it(s1[start], set))
		start++;
	len = ft_strlen(s1);
	if (start == len)
		return (chao());
	end = len - 1;
	while (is_it(s1[end], set))
		end--;
	out = malloc(sizeof(char) * (end - start + 2));
	if (!out)
		return (NULL);
	ft_strlcpy(out, (s1 + start), (end - start + 2));
	return (out);
}
