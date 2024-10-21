/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:10:56 by raphox            #+#    #+#             */
/*   Updated: 2024/10/13 17:25:10 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include "../includes/libft.h"


void echo(char *command, char *option, const char **arguments)
{
    int i;
    char *result;
    char *temp;

    i = 0;
    result = ft_strdup("");
    if (arguments != NULL && arguments != NULL)
    {
        free(result);
        result = ft_strdup(arguments[0]);
        i = 1;
        while (arguments[i] != NULL)
        {
            temp = ft_strjoin(result, arguments[i], 1);
            free(result);
            result = temp;
            i++;
        }
    }
	display_echo(command, option, arguments, result);
    free(result);
}


void display_echo(char *command, char *option, const char **arguments, char *result)
{
	if (command != NULL && option == NULL && arguments == 0)
	{
		write(1, "\n", 1);
		return ;
	}
	else if (command != NULL && option != NULL && option[0] == '-' && option[1] == 'n' && option[2] == '\0' && arguments == 0)
		return ;
	else if (command != NULL && option == NULL)
		printf("%s\n", result);
	else if (command != NULL && option != NULL && option[0] == '-' && option[1] == 'n')
		printf("%s", result); //pas de saut ligne avec -n
	return ;
}
