/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:08:38 by raphox            #+#    #+#             */
/*   Updated: 2024/10/30 17:03:30 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

int main(int argc, char **argv, char **envp)
{

	char	*rule;
	(void)argc;
	(void)argv;

	   t_data_rule first;
    const char *tab1[3] = {"Double monstre mon coeur", "Triple Monstre", NULL};
    first.command = "echo";
    first.options = NULL;
    first.arguments = tab1;
    first.nbr_args = 2;
    first.dir_path = NULL;
    first.oper = ">>";
    first.targetfile = "z.txt";
    first.pipe = true;

    t_data_rule second;
    const char *tab2[2] = {"coucoucoucoucoucoucou", NULL};
    second.command = "env";
    second.options = NULL;
    second.arguments = NULL;
    second.nbr_args = 0;
    second.dir_path = NULL;
    second.oper = ">>";
    second.targetfile = "z.txt";
    second.pipe = true;

    // t_data_rule third;
    // const char *tab3[2] = {"z.txt", NULL};
    // third.command = "wc";
    // third.options = "-l";
    // third.arguments = tab3;
    // third.nbr_args = 1;
    // third.dir_path = NULL;
    // third.oper = NULL;
    // third.targetfile = NULL;
    // third.pipe = true;

    t_data_rule data[2] = {first, second};


	// the_execution(request, envp);

	while (1)
	{
		rule = NULL;
		rule = readline("minishell->");
		if (rule != NULL) 
		{
			pipex(data, 2, envp);
		}
	}
	return 0;
}


int main(int argc, char **argv, char **envp)
{
    t_data_rule first;
    const char *tab1[3] = {"Double monstre mon coeur", "Triple Monstre", NULL};
    first.command = "echo";
    first.options = NULL;
    first.arguments = tab1;
    first.nbr_args = 2;
    first.dir_path = NULL;
    first.oper = ">>";
    first.targetfile = "z.txt";
    first.pipe = true;

    t_data_rule second;
    const char *tab2[2] = {"coucoucoucoucoucoucou", NULL};
    second.command = "env";
    second.options = NULL;
    second.arguments = NULL;
    second.nbr_args = 0;
    second.dir_path = NULL;
    second.oper = ">>";
    second.targetfile = "z.txt";
    second.pipe = true;

    // t_data_rule third;
    // const char *tab3[2] = {"z.txt", NULL};
    // third.command = "wc";
    // third.options = "-l";
    // third.arguments = tab3;
    // third.nbr_args = 1;
    // third.dir_path = NULL;
    // third.oper = NULL;
    // third.targetfile = NULL;
    // third.pipe = true;

    t_data_rule data[2] = {first, second};

    return pipex(data, 2, envp);

	// int fd[2];
	// pipe(fd);

	// if (pipe(fd) == -1)
	// {
	// 	printf("WRONG");
	// 	return (0);
	// }
	
	// int fichier;
	// fichier = open("z.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	// dup2(fichier, STDOUT_FILENO);
	
	exec_builtins(second, envp);

	
	
	// close(fd[0]);
	// close(fd[1]);
	// close(fichier);


}