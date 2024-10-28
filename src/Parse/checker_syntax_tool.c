#include "../../includes/Parsing.h"

int occurence(char *str)
{
	int		itr;
	char 	occ;

	occ = str[0];
	itr = 0;
	while (str[itr] && str[itr] == occ)
		itr++;
	printf("%d\n", itr);
	return (itr);
}