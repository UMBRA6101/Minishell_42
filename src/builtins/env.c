


#include "../includes/minishell.h"
// #include "../includes/Lexing.h"
#include "../includes/libft.h"

static char  **copy_env(char **envp)
{
	static char **env;
	env = envp;
	return (env);
}

void display_env(char **envp)
{
	int i;
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;

	}
}


// int main(int argc, char **argv, char **envp)
// {
// 	display_env(envp);

// }