/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:32:10 by thomas            #+#    #+#             */
/*   Updated: 2024/03/09 03:23:05 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*clean_buff(char *buff)
{
	char	*out;
	int		itr;
	int		itr_out;

	out = NULL;
	if (!buff || buff[0] == '\0')
		return (NULL);
	itr = 0;
	while (buff[itr] && buff[itr] != '\n')
		itr++;
	if (buff[itr] == '\n')
		itr++;
	out = ft_calloc(sizeof(char), (ft_strlen(buff) - itr + 1));
	if (!out)
		return (NULL);
	itr_out = 0;
	while (buff[itr] != '\0')
		out[itr_out++] = buff[itr++];
	free(buff);
	buff = NULL;
	return (out);
}

int	next_line(char *str)
{
	int	itr;

	itr = 0;
	if (str == NULL)
		return (0);
	while (str[itr] != '\0')
	{
		if (str[itr] == '\n')
			return (1);
		itr++;
	}
	return (0);
}

char	*stradd(char *buff, char *str, int readed)
{
	int		itr;
	int		itr_out;
	char	*str_out;

	str_out = NULL;
	if (!str)
		return (NULL);
	str_out = ft_calloc(sizeof(char), (ft_strlen(buff) + readed + 1));
	itr = 0;
	itr_out = 0;
	if (buff)
		while (buff[itr])
			str_out[itr_out++] = buff[itr++];
	itr = 0;
	while (str[itr] && itr < readed)
		str_out[itr_out++] = str[itr++];
	str_out[itr_out] = '\0';
	free(buff);
	buff = NULL;
	return (str_out);
}

void	read_to_buff(char **buff, int fd)
{
	char	*temp;
	int		readed;

	readed = 1;
	temp = NULL;
	while (!next_line(*buff) && readed > 0)
	{
		temp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!temp)
			return ;
		readed = read(fd, temp, BUFFER_SIZE);
		if (readed < 0 || (temp == NULL || readed == 0))
		{
			free(temp);
			temp = NULL;
			return ;
		}
		*buff = stradd(*buff, temp, readed);
		free(temp);
		temp = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buff, 0) < 0)
		return (NULL);
	read_to_buff(&buff, fd);
	extract_line(&line, buff);
	buff = clean_buff(buff);
	if (line == NULL || line[0] == '\0')
	{
		free(line);
		free(buff);
		line = NULL;
		buff = NULL;
		return (NULL);
	}
	if (buff[0] == '\0')
	{
		free(buff);
		buff = NULL;
	}
	return (line);
}
