#include "libft.h"

int ft_strcspn(const char *str, const char *sep)
{
	int itr_str;
	int itr_sep;

	itr_str = 0;
	while (str[itr_str])
	{
		itr_sep = 0;
		while (str[itr_str] == sep[itr_sep] && str[itr_str])
		{
			itr_str++;
			itr_sep++;
			if (sep[itr_sep] == '\0')
				return (itr_str);
		}
		itr_str++;
	}
	return (itr_str);
}