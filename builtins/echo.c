/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:10:56 by raphox            #+#    #+#             */
/*   Updated: 2024/09/24 18:03:20 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/Lexing.h"
#include "../includes/libft.h"


void echo(char *command, char *option, char **arguments)
{
	int i;
	i = 0;
	
	while (arguments[i])
	{
		ft_strjoin(arguments[0], arguments[i]);
		i++;
	}
	if (command != NULL && option[0] == '\0' && arguments[0] == '\0')
		write(1, "\n", 1);
	if (command != NULL && option[0] == '-' && option[1] == 'n' && arguments[0] == '\0')
		return ;
	if (command != NULL && option[0] == '\0')
		printf("%s\n", arguments);
	if (command != NULL && option[0] == '-' && option[1] == 'n')
		printf("%s", arguments); //pas de saut ligne avec -n
}


// int main(int argc, char *argv)
// {
// 	char command[] = "echo";
// 	char option[] = "";
// 	char arguments[] = "   ";
	
// 	echo(command, option, arguments);
// }