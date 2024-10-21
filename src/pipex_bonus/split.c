/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:56:25 by raphox            #+#    #+#             */
/*   Updated: 2024/10/18 10:23:20 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include "../includes/minishell.h"
#include "../includes/libft.h"


int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && (str[i] != c && str[i] != 9))
		{
			count++;
			while (str[i] && (str[i] != c && str[i] != 9))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_charcount(char *s, int index, char c)
{
	int	count;

	count = 0;
	while (s[index] && s[index] != c)
	{
		count++;
		index++;
	}
	return (count);
}

static char	*ft_strndup_custom(char *s, int *retindex, int index, int n)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (s[index] && i < n)
	{
		dup[i] = s[index];
		i++;
		index++;
	}
	*retindex = index;
	dup[i] = '\0';
	return (dup);
}

static void	ft_free(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

char	**ft_split_pipex(char *s, char c)
{
	int		i;
	int		j;
	int		wordcount;
	char	**splitter;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	wordcount = count_words(s, c);
	splitter = malloc(sizeof(char *) * (wordcount + 1));
	if (!splitter)
		return (NULL);
	while (j < wordcount)
	{
		if (s[i] != c)
		{
			splitter[j] = ft_strndup_custom(s, &i, i, ft_charcount(s, i, c));
			if (!splitter[j++])
				return (ft_free(splitter, j - 1), NULL);
		}
		i++;
	}
	splitter[j] = 0;
	return (splitter);
}
