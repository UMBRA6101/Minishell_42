/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:35:49 by raphox            #+#    #+#             */
/*   Updated: 2025/02/05 15:43:07 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	pwd[10000];

	getcwd(pwd, sizeof(pwd));
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	return ;
}
// cd extra ++

char *modify_arg(char **argv)
{
	int size;
	size = ft_strlen(argv[0]);

	char *modified_size;
	modified_size = malloc(ft_strlen(argv[0]) + 2);

	ft_strlcpy(modified_size, argv[0], size + 1);
	ft_strlcat(modified_size, "/",  size + 2);
	free(argv[0]);
	argv[0] = modified_size;
	return (argv[0]);
}
