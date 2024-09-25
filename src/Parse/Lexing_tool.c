//
// Created by umbra on 9/16/24.
//
#include "Lexing.h"

static int quote_change(int quote)
{
	if (quote == 1)
		quote = 0;
	else
		quote = 1;
	return (quote);
}

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
				quote = quote_change(quote);
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

static int	split_token(char **output, char *input)
{
	int	itr_input;
	int	token_size;
	int	quote;

	itr_input = 0;
	quote = 0;
	token_size = 0;
	while (input[itr_input])
	{
		while (input[itr_input] >= 33 && input[itr_input] <= 126)
		{
			if (input[itr_input] == '"' || input[itr_input] == '\'')
				quote = quote_change(quote);
			token_size++;
			itr_input++;
		}
		while (input[itr_input] == ' ')
		{
			if (quote)
			{
				itr_input++;
				token_size++;
			}
			else
				itr_input++;
		}
		if (!quote)
		{
			printf("itr : %d | token_size : %d | ad : %d\n", itr_input, token_size, itr_input - token_size);
			*output = malloc(sizeof(char) * token_size + 1);
			ft_strlcpy(*output, input, token_size + 1);
			token_size = 0;
			input += itr_input;
			itr_input = 0;
			printf("%s\n", *output);
			printf("-------------------------------\n");
			output++;
		}
	}
	output = '\0';
	return (0);
}

char **ft_lexing_split(char *buff)
{
	char **out;

	out = NULL;
	while (*buff == ' ')
		buff++;
	out = ft_calloc(sizeof(char *), count_word(buff) + 1);
	if (!out)
		return (NULL);
	if (split_token(out, buff) == -1)
	{
		free(out);
		return (NULL);
	}
	return (out);
}