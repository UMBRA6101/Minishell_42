#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_data_rule first;
    const char *tab1[4] = {"NULL", "NULL", "NULL", NULL};
    first.command = "ls";
    first.options = NULL;
    first.arguments = tab1;
    first.nbr_args = 3;
    first.dir_path = NULL;
    first.out = NULL;
    first.pipe = true;

    t_data_rule second;
    const char *tab2[3] = {"arg1", "arg2", NULL};
    second.command = "ls";
    second.options = NULL;
    second.arguments = tab2;
    second.nbr_args = 2;
    second.dir_path = NULL;
    second.out = NULL;
    second.pipe = true;

    t_data_rule third;
    const char *tab3[2] = {"argA", NULL};
    third.command = "ls";
    third.options = NULL;
    third.arguments = tab3;
    third.nbr_args = 1;
    third.dir_path = NULL;
    third.out = NULL;
    third.pipe = false;

    t_data_rule data[3] = {first, second, third};
	pipex

}




// ---------------------------------------------------------------------------------------------------


// int main(int argc, char **argv, char **envp)
// {

	
// 	pipex(argc, argv, envp);
	
// }







// int	main(int argc, char **argv, char **envp)
// {

	// char	*rule;
	// t_data_rule *request;

	// rule = NULL;

	// char **env;
	// env = envp;

// //---------------------------------
// 	t_data_rule first;

// 	const char *tab[4];
// 	tab[0] = "NULL";
// 	tab[1] = "NULL";
// 	tab[2] = "UNLL";
// 	tab[3] = NULL;

// 	// const char **tab;
// 	// *tab = NULL;

// 	first.command = "unset";
// 	first.options = NULL;
// 	first.arguments = NULL;
// // -----------------------------------------
// 	printf("FIRST ENV ----------------------------------------------------------------------------\n");
// 	display_env(envp);
// 	exec_builtins(first, envp);
// 	// display_env(envp);
// 	return (0);

//---------------------------------


	// rule = readline(PROMPT);
	// if (rule != NULL)
	// {
	// 	// request = parsing(rule);
	// 	exec_builtins(first, genv);
	// 	(void)request;
	// }
	// return (0);
// }
