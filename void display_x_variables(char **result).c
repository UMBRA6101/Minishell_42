void display_x_variables(char **result)
{

	int fd[2];
	pipe(fd);

	char buffer[100000];
	size_t	bytes_read;
	
	int i;
	i = 0;

	int count;
	count = 0;
	
	while (result[i] != NULL)
	{
		write(fd[1], "declare -x ", 11);
		write(fd[1], result[i], ft_strlen(result[i]));
		count = count + ft_strlen(result[i]) + 10;
		write(fd[1], "\n", 1);
		i++;
	}
	bytes_read = read(fd[0], buffer, sizeof(buffer));
	write(1, buffer, bytes_read);
	close(fd[0]);
	close(fd[1]);
	
}