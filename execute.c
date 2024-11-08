/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:08:38 by raphox            #+#    #+#             */
/*   Updated: 2024/11/08 14:47:11 by raphox           ###   ########.fr       */
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
	
	t_data_rule env;
    const char *tab1[3] = {"Double MONSTRE mon coeur", "Triple Monstre", NULL};
    env.command = "env";
    env.options = NULL;
    env.arguments = NULL;
    env.nbr_args = 0;
    env.dir_path = NULL;
    env.oper = NULL;
    env.targetfile = NULL;
    env.pipe = true;

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
    third.oper = NULL;
    third.targetfile = NULL;
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

	t_data_rule five;
    const char *tab5[4] = {"COUCOUCOUCOU", "BONJOURRRRRR", "yupp", NULL};
    five.command = "export";
    five.options = NULL;
    five.arguments = tab5;
    five.nbr_args = 3;
    five.dir_path = NULL;
    five.oper = NULL;
    five.targetfile = NULL;
    five.pipe = false;


	t_data_rule ls;
    const char *tab_ls	[0];
    ls.command = "ls";
    ls.options = "-l";
    ls.arguments = NULL;
    ls.nbr_args = 0;
    ls.dir_path = NULL;
    ls.oper = ">>";
    ls.targetfile = "z.txt";
    ls.pipe = true;

	t_data_rule grep;
    const char *tab_grep[2] = {"oct", NULL};
    grep.command = "grep";
    grep.options = NULL;
    grep.arguments = tab_grep;
    grep.nbr_args = 1;
    grep.dir_path = NULL;
    grep.oper = "<";
    grep.targetfile = "z.txt";
    grep.pipe = true;

	t_data_rule pwd;
    // const char *tab_grep[2] = {"oct", NULL};
    pwd.command = "pwd";
    pwd.options = NULL;
    pwd.arguments = NULL;
    pwd.nbr_args = 0;
    pwd.dir_path = NULL;
    pwd.oper = NULL;
    pwd.targetfile = NULL;
    pwd.pipe = false;

	t_data_rule cd;
    const char *tab_cd[2] = {"/home/raphox/Desktop/Test", NULL};
    cd.command = "cd";
    cd.options = NULL;
    cd.arguments = tab_cd;
    cd.nbr_args = 1;
    cd.dir_path = NULL;
    cd.oper = NULL;
    cd.targetfile = NULL;
    cd.pipe = false;



	t_data_rule unset;
    const char *tab_unset[5] = {"LS_COLORS", "PATH", "DBUS_SESSION_BUS_ADDRESS", "VAR1=", NULL};
    unset.command = "unset";
    unset.options = NULL;
    unset.arguments = tab_unset;
    unset.nbr_args = 4;
    unset.dir_path = NULL;
    unset.oper = NULL;
    unset.targetfile = NULL;
    unset.pipe = false;

	t_data_rule export;
    const char *tab6[3] = {"babygirl=", "et ta mama la gnetille=", NULL};
    export.command = "export";
    export.options = NULL;
    export.arguments = tab6;
    export.nbr_args = 2;
    export.dir_path = NULL;
    export.oper = NULL;
    export.targetfile = NULL;
    export.pipe = false;
	// // envv = export("export", tab4, envv);
	// allocate_new_env_to_add_variable(envv);
	// display_env(envv);
	// free(envv);
    // t_data_rule data[2] = {second, forth};
    // t_data_rule data2[1] = {second};
    // // t_data_rule data3[1] = {third};
    // // t_data_rule data3[1] = {five};
    // t_data_rule pwd_export[2] = {pwd, export};
    // t_data_rule data4[1] = {forth};
    // t_data_rule data2[2] = {first, second};
    // t_data_rule data3[3] = {first, second, third};
    // t_data_rule data4[4] = {first, second, forth, third};    
    // t_data_rule data1[4] = {first, second, third, forth};

	// t_data_rule cmd_env[1] = {env};

	// t_data_rule cmd_pwd[1] = {pwd};
	
	// t_data_ru	le cmd_grep[1] = {grep};
	
    // t_data_rule cmd_ls[1] = {ls};

    // t_data_rule cmd_export[1] = {export};

    // t_data_rule cmd_cd[1] = {cd};

    // t_data_rule cmd_unset[1] = {unset};

	
	

	// envv = unset("unset", tab_unset, envv);
	// display_env(envv);

	while (1)
	{
		rule = NULL;
		rule = readline("minishell->");
		if (rule != NULL)
		{
			// envv = pipex(cmd_export, 1, envv);
			
			// display_env(envv);

			// envv = pipex(cmd_unset, 1, envv);
			// envv = cd("cd", NULL, envv);
			// envv = pipex(cmd_cd, 1, envv);
			// display_env(envv);
			// write(2, "\n\n\n", 3);
			// display_env(envv);
			// envv = pipex(cmd_cd, 1, envv);
			// envv = pipex(cmd_env, 1, envv);
			// envv = pipex(cmd_grep, 1, envv);
			// envv = pipex(cmd_ls, 1, envv);
			// envv = pipex(pwd_export, 2, envv);
			// envv = pipex(data2, 1, envv);
			// envv = pipex(data11, 1, envv);
			// envv = pipex(data4, 1, envv);
			// printf("\n\n\n\n");
			// envv = pipex(data1, 3, envv);
			// envv = pipex(data3, 1, envv);
			// display_env(envv);
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