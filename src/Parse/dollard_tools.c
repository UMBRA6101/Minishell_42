/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollard_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:09:33 by thodos-s          #+#    #+#             */
/*   Updated: 2025/01/22 12:09:36 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	size_word(char *str);

static int	size_word(char *str)
{
	int	rank;

	rank = 0;
	while (str[rank] && ft_isalnum(str[rank]))
		rank++;
	return (rank);
}

int	ft_search(char *str, char c)
{
	int	rank;

	rank = 0;
	while (str[rank] && str[rank] != c)
		rank++;
	if (str[rank] != c)
		return (0);
	return (rank);
}

/*	verify the existence of a variable in the environment	*/
int	dollard_exist(char *rqst, t_info **data, int *index)
{
	int	i;
	int	size;

	i = 0;
	size = size_word(rqst + (*index) + 1);
	if (rqst[*index + 1] == '?' || rqst[(*index) + 1] == '$')
		return (2);
	while ((*data)->envv[i] != NULL)
	{
		if (size == ft_search((*data)->envv[i], '=')
			&& ft_strncmp((*data)->envv[i], rqst + (*index) + 1, \
				ft_search((*data)->envv[i], '=')) == 0)
			return (1);
		i++;
	}
	return (0);
}

/* give the correct part variable */
char	*give_word(char *rqst, int *index, t_info **data)
{
	char	*word;
	int		i;
	int		size;
	int		word_size;

	word = NULL;
	i = 0;
	size = size_word(rqst + (*index) + 1);
	while (((*data)->envv[i]))
	{
		word_size = ft_search((*data)->envv[i], '=');
		if (word_size == size && \
			ft_strncmp((*data)->envv[i], rqst + (*index) + 1, word_size) == 0)
			break ;
		i++;
	}
	(*index) += size + 1;
	word = ft_calloc(sizeof(char), ft_strlen((*data)->envv[i] + size + 1) + 2);
	if (!word)
		return (NULL);
	ft_strlcpy(word, (*data)->envv[i] + size + 1, \
		ft_strlen((*data)->envv[i]) - size);
	return (word);
}

/* add in buffer the correct environment variable to the buffet */
void	dollard_env(char *rqst, int *index, char **str, t_info **data)
{
	char	*word;
	char	*tmp;

	word = NULL;
	word = give_word(rqst, index, data);
	tmp = ft_strjoin(*str, word, 0);
	if (word)
		free(word);
	free(*str);
	if (!tmp)
		return ;
	*str = tmp;
}
