//
// Created by umbra on 10/3/24.
//
#include "../../includes/Parsing.h"
#include "../../includes/minishell.h"

static int 	node_finish(char *buff, int len)
{
	if (!buff || buff == NULL)
		return (1);
	if (ft_strncmp(buff, "|", len) == 0 || check_rdir(buff, len) != OTHER)
		return (1);
	return (0);
}

int	check_rdir(char *buff, int len)
{
	if (ft_strncmp(buff, ">", len) == 0)
		return (RDIR);
	if (ft_strncmp(buff, ">>", len) == 0)
		return (D_RDIR);
	if (ft_strncmp(buff, "|", len) == 0)
		return (PIPE);
	else
		return (OTHER);
}

int check_first(const t_split *split, int i)
{
	int k;
	int quote;

	k = 0;
	quote = 0;
	while (split[i].word[k])
	{
		if (split[i].word[k] == '\"')
		{
			if (quote == 0)
				quote = 1;
			else
				quote = 0;
		}
		if (split[i].word[k] == '=' && quote)
			return (VARIABLE);
	}
	return (OTHER);
}

int r_node(t_split *split, int nb_node)
{
	int node_type;

	node_type = 0;
	if (split[nb_node].word == NULL)
	{
		printf("nb_node : %d\n", nb_node);
		return (nb_node);
	}
	if (node_finish(split[nb_node].word, split[nb_node].len_word))
		return (nb_node);
	node_type = check_rdir(split->word, split->len_word);
	nb_node++;
	printf("%d\n", node_type);
	if (node_type == OTHER)
		r_node(split, nb_node);
	else
		return (nb_node);
}
