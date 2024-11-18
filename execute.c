/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:08:38 by raphox            #+#    #+#             */
/*   Updated: 2024/11/18 15:31:19 by raphox           ###   ########.fr       */
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
	
	t_data_rule cat;
	// char *tab_cat[2] = {"split", NULL};
	char tab_oper_cat[5] = {'h', 'r', '>', 'r', 0};
	char *tab_out_cat[5] = {"pipi", "x.txt", "y.txt", "z.txt", 0}; //  le input doit etre au debut
    cat.command = "cat";
    cat.options = NULL;
    cat.arguments = NULL;
	cat.input = "bonjour"; // input sert aussi mot terminant le heredoc
    cat.out = tab_out_cat;
    cat.oper = tab_oper_cat;
	cat.nbr_args = 0; // ne compte pas le nul
    cat.dir_path = NULL;
    cat.pipe = true;




	t_data_rule grep;
	char *tab_grep[2] = {"VAR1=BONNNNNNJOUUUUUUUUUUUURRRRRRRRRRRRRRRRr", NULL};
	char tab_oper_grep[3] = {'<', 0};
	char *tab_out_grep[3] = {"x.txt", NULL};
    grep.command = "grep";
    grep.options = NULL;
    grep.arguments = tab_grep;
	grep.input = "x.txt"; // input sert aussi mot terminant le heredoc
    grep.out = tab_out_grep;
    grep.oper = tab_oper_grep;
	grep.nbr_args = 1; // ne compte pas le nul
    grep.dir_path = NULL;
    grep.pipe = false;
    t_data_rule cmd_grep[1] = {grep};

	t_data_rule ls;
	char *tab_ls[0];
	char tab_oper_ls[4] = {'r', '>', 'r', 0};
	char *tab_out_ls[4] = {"x.txt", "y.txt", "z.txt", NULL};
    ls.command = "ls";
    ls.options = NULL;
    ls.arguments = NULL;
	ls.input = NULL;
	ls.out = NULL ;
	// ls.out = tab_out_ls;
	ls.oper = NULL;
	// ls.oper = tab_oper_ls;
	ls.nbr_args = 0;
    ls.dir_path = NULL;
    ls.pipe = true;
    t_data_rule cmd_ls[1] = {ls};


	t_data_rule env;
	// char *tab_env[0];
	char tab_oper[2] = {'r', 0};
	char *tab_out[2] = {"x.txt", NULL};
    env.command = "env";
    env.options = NULL;
    env.arguments = NULL;
	env.input = NULL;
	env.out = NULL ;
	env.out = tab_out;
	// env.oper = NULL;
	env.oper = tab_oper;
	env.nbr_args = 0;
    env.dir_path = NULL;
    env.pipe = true;
    t_data_rule cmd_env[1] = {env};


	t_data_rule env_second;
	// char *tab_env_second[0];
	// char tab_oper[4] = {'r', '>', 'r', 0};
	// char *tab_out[4] = {"x.txt", "y.txt", "z.txt", NULL};
    env_second.command = "env";
    env_second.options = NULL;
    env_second.arguments = NULL;
	env_second.input = NULL;
	env_second.out = NULL ;
	env_second.out = tab_out;
	// env_second.oper = NULL;
	env_second.oper = tab_oper;
	env_second.nbr_args = 0;
    env_second.dir_path = NULL;
    env_second.pipe = false;
    t_data_rule cmd_env_second[1] = {env_second};




    // t_data_rule cmd_env_x2[2] = {env, env_second};


    // // t_data_rule cmd_ls_grep[2] = {ls, grep};
	// // envv = pipex(cmd_ls_grep, 2, envv);

	// envv = pipex(cmd_env_x2, 2, envv);

	// 	display_env(envv);

	char *tab_unset[2] = {NULL, NULL};

	// // envv = export("export", tab_grep, envv);
	envv = unset("unset", NULL, envv);

	display_env(envv);
	
	free_env(envv);
	return 0;





			
	// t_data_rule cmd_ls[1] = {grep};
	// envv = pipex(cmd_ls, 2, envv);
	
	// while (1)
	// {
	// 	rule = NULL;
	// 	rule = readline("minishell->");
	// 	if (rule != NULL)
	// 	{

	// 	}
	// }
}





// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./pipex



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



	// t_data_rule export;
    //  char *tab6[3] = {"babygirl=", "et ta mama la gnetille=", NULL};
    // export.command = "export";
    // export.options = NULL;
    // export.arguments = tab6;
    // export.nbr_args = 2;
    // export.dir_path = NULL;
    // export.oper = NULL;
    // export.out = NULL;
    // export.pipe = false;
    // t_data_rule cmd_export[1] = {export};
	// t_data_rule env;
    // char *tab1[3] = {"Double MONSTRE mon coeur", "Triple Monstre", NULL};
    // env.command = "env";
    // env.options = NULL;
    // env.arguments = NULL;
    // env.nbr_args = 0;
    // env.dir_path = NULL;
    // env.oper = NULL;
    // env.out = NULL;
    // env.pipe = true;

	// t_data_rule grep;
    //  char *tab_grep[2] = {"oct", NULL};
    // grep.command = "grep";
    // grep.options = NULL;
    // grep.arguments = tab_grep;
    // grep.nbr_args = 1;
    // grep.dir_path = NULL;
    // grep.oper = "<";
    // grep.out = "z.txt";
    // grep.pipe = true;

	// t_data_rule pwd;
    // //  char *tab_grep[2] = {"oct", NULL};
    // pwd.command = "pwd";
    // pwd.options = NULL;
    // pwd.arguments = NULL;
    // pwd.nbr_args = 0;
    // pwd.dir_path = NULL;
    // pwd.oper = NULL;
    // pwd.out = NULL;
    // pwd.pipe = false;

	// t_data_rule cd;
    //  char *tab_cd[2] = {"/home/raphox/Desktop/Test", NULL};
    // cd.command = "cd";
    // cd.options = NULL;
    // cd.arguments = tab_cd;
    // cd.nbr_args = 1;
    // cd.dir_path = NULL;
    // cd.oper = NULL;
    // cd.out = NULL;
    // cd.pipe = false;



	// t_data_rule unset;
    //  char *tab_unset[5] = {"LS_COLORS", "PATH", "DBUS_SESSION_BUS_ADDRESS", "VAR1=", NULL};
    // unset.command = "unset";
    // unset.options = NULL;
    // unset.arguments = tab_unset;
    // unset.nbr_args = 4;
    // unset.dir_path = NULL;
    // unset.oper = NULL;
    // unset.out = NULL;
    // unset.pipe = false;

	
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
    // t_data_rule cmd_cd[1] = {cd};
    // t_data_rule cmd_unset[1] = {unset};
	// envv = unset("unset", tab_unset, envv);

	
// typedef struct 	s_data_rule
// {
// 	char	*command;
// 	char *options;
// 	char 		**arguments;
// 	int 	nbr_args;
// 	char	*dir_path;
// 	char	*out; // il faut free
// 	char	*input;
// 	char 	oper; // r = >>
// 	bool 	pipe;
// 	int 	nb_command;
// }				t_data_rule;	


// typedef struct s_data_rule
// {	
//     char *command;
//     char *options;
//     char **arguments;
	
	
// 	char *targetfile;
//     int nbr_args;
//     char *dir_path;
// 	char *oper;
//     bool pipe;

// } t_data_rule;
	// -----------------------------------------------------------------------------------











			
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