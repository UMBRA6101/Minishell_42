/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:17:46 by raphox            #+#    #+#             */
/*   Updated: 2025/01/29 15:30:46 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t		g_pid;

void	print_request(t_data_rule *request)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!request)
		return ;
	while (k < request[0].nb_command)
	{
		i = 0;
		printf("-----------------\n");
		printf("command : %s\n", request[k].command);
		printf("nbr_arg : %d\n", request[k].nbr_args);
		if (request[k].options)
		{
			i = 0;
			while (request[k].options[i])
			{
				printf("option[%d] : %s\n", i, request[k].options[i]);
				i++;
			}
		}
		if (request[k].arguments)
		{
			i = 0;
			while (i < request[k].nbr_args)
			{
				printf("arg[%d] : |%s|\n", i, request[k].arguments[i]);
				i++;
			}
		}
		if (request[k].out)
		{
			i = 0;
			printf("nb_dir : %d\n", request[k].nb_rdir);
			while (request[k].out[i] && i < request[k].nb_rdir)
			{
				printf("out : %s\n", request[k].out[i]);
				i++;
			}
		}
		printf("input : %s\n", request[k].input);
		if (request[k].oper && i <= request[k].nb_rdir)
		{
			i = 0;
			while (request[k].oper[i])
			{
				printf("oper : %c\n", request[k].oper[i]);
				i++;
			}
		}
		printf("pipe : %d\n", request[k].pipe);
		printf("nb_command : %d\n", request[k].nb_command);
		k++;
	}
	printf("------------------------------------------\n");
}
/*	initialisation of minishell struct	*/

int	init(t_info **info, char **envp)
{
	signal(SIGINT, signal_treatment);
	signal(SIGQUIT, SIG_IGN);
	*info = malloc(sizeof(t_info) * 1);
	if (!*info)
		return (-1);
	(*info)->envv = ft_strdup_env(envp);
	if ((*info)->envv == NULL)
	{
		unlink(TMP_FILES);
		return (0);
	}
	(*info)->cmd = NULL;
	(*info)->err = malloc(sizeof(t_erreur) * 1);
	if (!(*info)->err)
	{
		free(info);
		return (-1);
	}
	(*info)->err->c = '\0';
	(*info)->err->error_code = -1;
	(*info)->err->exit_value = 0;
	return (0);
}

static int	parse_exec(t_info **info, char *rule)
{
	(*info)->cmd = parsing((*info), &rule);
	if (!(*info)->cmd)
		print_parsing_error((*info)->err);
	else
	{
		print_request((*info)->cmd);
		(*info)->envv = pipex((*info)->cmd, (*info)->err,
				(*info)->cmd->nb_command, (*info)->envv);
		if ((*info)->envv == NULL)
		{
			killer_request((*info)->cmd);
			unlink(TMP_FILES);
			return (-1);
		}
	}
	killer_request((*info)->cmd);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*rule;
	t_info	*info;

	(void)argc;
	(void)argv;
	write_temp_file(TMP_FILES, 0);
	if (init(&info, envp) == -1)
		return (0);
	while (42)
	{
		info->err->error_code = -1;
		rule = readline(PROMPT);
		if (rule == NULL || !rule)
			free_all(&info, rule, 0);
		if (rule != NULL)
		{
			add_history(rule);
			if (parse_exec(&info, rule) == -1)
				return (0);
		}
		if (ask_tmp_files() == 1024 || ask_tmp_files() == 1025)
			info->err->exit_value = ask_tmp_files() - 894;
	}
	unlink(TMP_FILES);
	return (0);
}

char	**ft_strdup_env(char **envp)
{
	int		i;
	char	**new_env;

	if (count_arguments(envp) == 0 || count_arguments(envp) == 2)
		return (init_minimal_env());
	i = 0;
	while (envp[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (new_env == NULL)
		return (perror("malloc"), NULL);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		if (new_env[i] == NULL)
		{
			perror("ft_strdup");
			return (NULL);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

char	**init_minimal_env(void)
{
	char	**new_env;
	char	pwd[1024];

	getcwd(pwd, sizeof(pwd));
	new_env = (char **)malloc(sizeof(char *) * (7));
	new_env[0] = strdup("SHLVL=1");
	new_env[1] = strdup("TERM=xterm");
	new_env[2] = strdup("_=./minishell");
	new_env[3] = ft_strjoin("PWD=", pwd, 0);
	new_env[4] = ft_strjoin("OLDPWD=", "/home/raphox/Music/minishell", 0);
	new_env[5] = strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	new_env[6] = NULL;
	return (new_env);
}
