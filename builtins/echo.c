/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:10:56 by raphox            #+#    #+#             */
/*   Updated: 2024/09/22 20:26:48 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include <unistd.h>


void echo(char *command, char *option, char *arguments)
{
	if (command != NULL && option[0] == '\0' && arguments[0] == '\0')
		write(1, "\n", 1);
	if (command != NULL && option[0] == '-' && option[1] == 'n' && arguments[0] == '\0')
		return ;
	if (command != NULL && option[0] == '\0')
		printf("%s", arguments);
	if (command != NULL && option[0] == '-' && option[1] == 'n')
		printf("%s\n", arguments);
}


// int main(int argc, char *argv)
// {
// 	char command[] = "echo";
// 	char option[] = "";
// 	char arguments[] = "   ";
	
// 	echo(command, option, arguments);
// }