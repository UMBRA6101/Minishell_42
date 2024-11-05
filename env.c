


#include "pipex_bonus.h"
#include "libft/libft.h"

// static char  **copy_env(char **envp)
// {
// 	static char **env;
// 	env = envp;
// 	return (env);
// }

void display_env(char **envv)
{
	int fd[2];
	pipe(fd);

	char buffer[100000];
	size_t	bytes_read;
	
	int i;
	i = 0;
	
	while (envv[i] != NULL)
	{
		write(fd[1], envv[i], ft_strlen(envv[i]));
		write(fd[1], "\n", 1);
		i++;
	}
	bytes_read = read(fd[0], buffer, sizeof(buffer));
	write(1, buffer, bytes_read);
	close(fd[0]);
	close(fd[1]);
}


// int main(int argc, char **argv, char **envp)
// {
// 	display_env(envp);