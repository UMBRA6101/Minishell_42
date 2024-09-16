//
// Created by umbra on 9/16/24.
//
#include "Lexing.h"

static int	count_word(char *buff)
{
	int	nbr_word;
	int	itr_buff;
	int	quote;

	nbr_word = 0;
	itr_buff = 0;
	quote = 0;
	while (buff[itr_buff] != 0)
	{
		while(buff[itr_buff] && (buff[itr_buff] >= 33 && buff[itr_buff] <= 126))
		{
			if (buff[itr_buff] == '"' || buff[itr_buff] == '\'')
			{
				if (quote == 0)
					quote = 1;
				else
					quote = 0;
			}
			itr_buff++;
		}
		while(buff[itr_buff] && buff[itr_buff] == ' ')
			itr_buff++;
		if (quote != 1)
			nbr_word++;
	}
	printf("%d\n", nbr_word);
	return (nbr_word);
}

static char

char **ft_lexing_split(char *buff)
{
	char	**out;

	out = NULL;
	out = malloc(sizeof(char *) * count_word(buff) + 1);
	while
	return (NULL);
}

int	main()
{
	char	**test;

	test = NULL;#include <stdio.h>
	test = ft_lexing_split("yo je 'hey you' suis la");
	return (0);
}
