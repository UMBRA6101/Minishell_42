/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:08:38 by raphox            #+#    #+#             */
/*   Updated: 2024/11/05 21:22:57 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

int main(int argc, char **argv, char **envp)
{

	char	*rule;
	(void)argc;
	(void)argv;

	char **envv;
	envv = ft_strdup_env(envp);
	
	t_data_rule first;
    const char *tab1[3] = {"Double MONSTRE mon coeur", "Triple Monstre", NULL};
    first.command = "env";
    first.options = NULL;
    first.arguments = NULL;
    first.nbr_args = 0;
    first.dir_path = NULL;
    first.oper = NULL;
    first.targetfile = NULL;
    first.pipe = true;

    t_data_rule second;
    const char *tab2[2] = {"MON ANCIEN CHEMINNNNNN", NULL};
    second.command = "export";
    second.options = NULL;
    second.arguments = tab2;
    second.nbr_args = 2;
    second.dir_path = NULL;
    second.oper = NULL;
    second.targetfile = NULL;
    second.pipe = true;

    t_data_rule third;
    third.command = "env";
    third.options = NULL;
    third.arguments = NULL;
    third.nbr_args = 0;
    third.dir_path = NULL;
    third.oper = ">>";
    third.targetfile = "z.txt";
    third.pipe = true;


	t_data_rule forth;
    const char *tab4[4] = {"COUCOUCOUCOU", "BONJOURRRRRR", "yupp", NULL};
    forth.command = "export";
    forth.options = NULL;
    forth.arguments = tab4;
    forth.nbr_args = 3;
    forth.dir_path = NULL;
    forth.oper = NULL;
    forth.targetfile = NULL;
    forth.pipe = true;

	// envv = export("export", tab4, envv);
	// allocate_new_env_to_add_variable(envv);
	// display_env(envv);
	// free(envv);
    // t_data_rule data[2] = {second, forth};
    // t_data_rule data2[1] = {second};
    // // t_data_rule data3[1] = {third};
    // t_data_rule data4[1] = {forth};
	
	
    // t_data_rule data1[1] = {forth};
    // t_data_rule data2[2] = {first, second};
    // t_data_rule data3[3] = {first, second, third};
    t_data_rule data4[4] = {first, second, third, forth};
    

	// t_data_rule data6[1] = {forth};

	

	
	while (1)
	{
		rule = NULL;
		rule = readline("minishell->");
		if (rule != NULL) 
		{
			envv = pipex(data4, 4, envv);
			// display_env(envv);
			
			// envv = pipex(data1, 1, envv);
			// display_env(envv);
			// envv = pipex(data2, 1, envv);
			// envv = pipex(data4, 1, envv);
			// envv = pipex(data2, 1, envv);
			// pipex(data3, 1, envv);
			// pipex(data, 2, envp);
			// pipex(data, 3, envv);
		}
	}
	free_env(envv);
	return 0;
}


char **ft_strdup_env(char **envp)
{
    int i = 0;
    char **new_env;

    while (envp[i])
        i++;

    new_env = (char **)malloc(sizeof(char *) * (i + 1));
    if (!new_env)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (envp[i])
    {
        new_env[i] = ft_strdup(envp[i]);
        if (!new_env[i])
        {
            perror("ft_strdup");
            exit(EXIT_FAILURE);
        }
        i++;
    }
	new_env[i] = NULL;
    return new_env;
}





































// char **copy_the_env(char **envp)
// {
//     int i = 0;
//     while (envp[i])
//         i++;

//     char **env_copy = malloc((i + 1) * sizeof(char *));
//     if (!env_copy)
//     {
//         perror("Erreur d'allocation mémoire");
//         exit(EXIT_FAILURE);
//     }

//     for (int j = 0; j < i; j++)
//     {
//         env_copy[j] = strdup(envp[j]);
//         if (!env_copy[j])
//         {
//             perror("Erreur de copie de l'environnement");
//             exit(EXIT_FAILURE);
//         }
//     }
//     env_copy[i] = NULL;

//     return env_copy;
// }

















// int main(int argc, char **argv, char **envp)
// {
//     t_data_rule first;
//     const char *tab1[3] = {"Double monstre mon coeur", "Triple Monstre", NULL};
//     first.command = "echo";
//     first.options = NULL;
//     first.arguments = tab1;
//     first.nbr_args = 2;
//     first.dir_path = NULL;
//     first.oper = ">>";
//     first.targetfile = "z.txt";
//     first.pipe = true;

//     t_data_rule second;
//     const char *tab2[2] = {"coucoucoucoucoucoucou", NULL};
//     second.command = "env";
//     second.options = NULL;
//     second.arguments = NULL;
//     second.nbr_args = 0;
//     second.dir_path = NULL;
//     second.oper = ">>";
//     second.targetfile = "z.txt";
//     second.pipe = true;

//     // t_data_rule third;
//     // const char *tab3[2] = {"z.txt", NULL};
//     // third.command = "wc";
//     // third.options = "-l";
//     // third.arguments = tab3;
//     // third.nbr_args = 1;
//     // third.dir_path = NULL;
//     // third.oper = NULL;
//     // third.targetfile = NULL;
//     // third.pipe = true;

//     t_data_rule data[2] = {first, second};

//     return pipex(data, 2, envp);

// 	// int fd[2];
// 	// pipe(fd);

// 	// if (pipe(fd) == -1)
// 	// {
// 	// 	printf("WRONG");
// 	// 	return (0);
// 	// }
	
// 	// int fichier;
// 	// fichier = open("z.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
// 	// dup2(fichier, STDOUT_FILENO);
	
// 	exec_builtins(second, envp);

	
	
// 	// close(fd[0]);
// 	// close(fd[1]);
// 	// close(fichier);


// }