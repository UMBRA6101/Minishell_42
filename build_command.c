/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:02:21 by raphox            #+#    #+#             */
/*   Updated: 2024/11/06 17:28:21 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
# include "libft/libft.h"

#include "pipex_bonus.h"

char    **build_command(t_data_rule data)
{
    char    **cmd;
    char    **split_command;
    int     i;
    int     j;

    j = count_options(data.options, &split_command);
    cmd = allocate_command(j, data.nbr_args);
    if (!cmd)
    {
        free_command(split_command);
        return (NULL);
    }
    i = copy_command_to_cmd(cmd, data.command);
    if (i == -1)
    {
        free_command(split_command);
        return (NULL);
    }
    if (!copy_options_to_cmd(cmd, split_command, &i, j) ||
        !copy_arguments_to_cmd(cmd, data.arguments, &i, data.nbr_args))
    {
        free_command(cmd);
        return (NULL);
    }
    cmd[i] = NULL;
    return (cmd);
}

int    count_options(char *options, char ***split_command)
{
    int j;

    j = 0;
    *split_command = NULL;
    if (options)
    {
        *split_command = ft_split(options, ' ');
        while (*split_command && (*split_command)[j])
            j++;
    }
    return (j);
}

char    **allocate_command(int options_count, int nbr_args)
{
    return malloc((options_count + nbr_args + 2) * sizeof(char *));
}

int    copy_command_to_cmd(char **cmd, char *command)
{
    cmd[0] = strdup(command);
    if (!cmd[0])
        return (-1);
    return (1);
}

int    copy_options_to_cmd(char **cmd, char **split_command, int *i, int j)
{
    int k;

    k = 0;
    while (k < j)
    {
        cmd[*i] = strdup(split_command[k++]);
        if (!cmd[*i])
            return (0);
        (*i)++;
    }
    free_command(split_command);
    return (1);
}

int    copy_arguments_to_cmd(char **cmd, const char **arguments, int *i, int nbr_args)
{
    int k;

    k = 0;
    while (k < nbr_args)
    {
        cmd[*i] = strdup(arguments[k++]);
        if (!cmd[*i])
            return (0);
        (*i)++;
    }
    return (1);
}
