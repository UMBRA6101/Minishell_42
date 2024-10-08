/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:10:56 by raphox            #+#    #+#             */
/*   Updated: 2024/10/08 17:32:44 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include "../includes/libft.h"


void echo(char *command, char *option, const char **arguments)
{
	int i;
	i = 0;
	
	if (arguments != NULL)
	{
		if (arguments[i + 1] != 0)
		{
			i = 1;
			while (arguments[i] != 0)
			{
				arguments[0] = ft_strjoin(arguments[0], arguments[i]);
				i++;
			}
		}
	}
	
	if (command != NULL && option == NULL && arguments == 0)
	{
		write(1, "\n", 1);
		return ;
	}
	
	if (command != NULL && option != NULL && option[0] == '-' && option[1] == 'n' && option[2] == '\0' && arguments == 0)
		return ;
		
	if (command != NULL && option == NULL)
	{
		printf("%s\n", arguments[0]);
		return ;
	}
		
	if (command != NULL && option != NULL && option[0] == '-' && option[1] == 'n')
	{
		printf("%s", arguments[0]); //pas de saut ligne avec -n
		return ;
	}
}


// int main(int argc, char *argv)
// {
// 	char command[] = "echo";
// 	char option[] = "";
// 	char arguments[] = "   ";
	
// 	echo(command, option, arguments);
// }