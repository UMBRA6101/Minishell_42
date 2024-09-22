/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:30:17 by raphox            #+#    #+#             */
/*   Updated: 2024/09/22 18:41:13 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "../includes/minishell.h"
// #include "../includes/Lexing.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	ft_strlen_perso(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_blyat_strlcpy(char *blyat, char *dst, const char *src,
		size_t dstsize)
{
	size_t	i;
	int		l;

	l = 0;
	if (blyat == NULL)
		return (NULL);
	if (!dst || !src)
		return (0);
	i = ft_strlen(blyat);
	if (dstsize != 0)
	{
		while (src[l] != '\0')
		{
			blyat[i] = src[l];
			i++;
			l++;
		}
		blyat[i] = '\0';
	}
	return (blyat);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*src;
	int		count1;
	int		count2;
	char	*suka;

	dest = (char *)s1;
	src = (char *)s2;
	count1 = ft_strlen_perso(dest);
	count2 = ft_strlen_perso(src);
	suka = malloc((sizeof(char)) * (count1 + count2) + 1);
	if (suka == NULL)
		return (NULL);
	suka[0] = '\0';
	suka = ft_blyat_strlcpy(suka, &dest[0], dest, count1);
	suka = ft_blyat_strlcpy(suka, &dest[count1], src, count2);
	return (suka);
}

// void modify_pwd()
// {
	
// }

void cd(char *command, char *arguments, char **envp)
{
	const char *path;
	const char *user;
	
	if (command != 0 && arguments[0] == '\0') // > cd (fait mais inutile, car pas demander)
	{
		chdir(getenv("HOME"));
		// printf("%d",chdir(path));
	}

	if (command != 0 && arguments[0] != 0) // > cd "arguments"
	{
		chdir(arguments);
		envp[64] = arguments;
	}
	

}

// int main(int argc, char **argv, char **envp)
// {
// 	char command[] = "cd";
// 	char arguments[] = "/home/raphox/Desktop";
// 	// printf("%s", envp[3]);
// 	cd(command, arguments, envp);
// }