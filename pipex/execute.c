/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:10:20 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/20 21:04:21 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../minishell.h"

void	ft_first_one(char *av, int *pip, char **env)
{
	char	**cmd;
	char	*fp;
	int		i;

	cmd = ft_split(av, ' ');
	fp = ft_search_path(cmd[0], env, pip);
	if (!fp)
	{
		write(2, "bash: command not found: ", 25);
		i = 0;
		while (cmd[0][i])
			write(2, &cmd[0][i++], 1);
		ft_exit(pip);
	}
	close(pip[0]);
	if (dup2(pip[1], 1) == -1)
		ft_exit(pip);
	printf("%s\n",fp);
	printf("%s\n",cmd[0]);
	execve(fp, cmd, env);
	ft_exit(pip);                                                                                                                                                                                                                                          
}

void	ft_cmd_execute(char *av, int *pip, char **env)
{
	char	**cmd;
	char	*fp;
	int		i;

	cmd = ft_split(av, ' ');
	fp = ft_search_path(cmd[0], env, pip);
	if (!fp)
	{
		write(2, "bash: command not found: ", 25);
		i = 0;
		while (cmd[0][i])
			write(2, &cmd[0][i++], 1);
		write(2, "\n", 1);
		ft_exit(pip);
	}
	close(pip[0]);
	if (dup2(pip[1], 1) == -1)
	{
		ft_exit(pip);
	}
	int j = execve(fp, cmd, env);
	printf("%d\n", j);
	ft_exit(pip);
}

void	ft_execute_one_cmd(char *av, int *pip, char **env)
{
	char	**cmd;
	char	*fp;
	int		i;

	// pipe(pip);
	cmd = ft_split(av, ' ');
	fp = ft_search_path(cmd[0], env, pip);
	if (!fp)
	{
		write(2, "zsh: command not found: ", 24);
		i = 0;
		while (cmd[0][i])
			write(2, &cmd[0][i++], 1);
		ft_exit(pip);
	}
	int j = execve(fp, cmd, env);
	printf("%d\n", j);
	ft_exit(pip);
}

void	ft_cmd_loop(t_exct *hadik, char **env)
{
	t_detail	var;
	int	pip[2];
	int		a;

	a = 0;
	ft_var_init(&var);
	while (hadik->arg[var.i])
		var.i++;
	if (--var.i == 1)
		ft_execute_one_cmd(hadik->arg, pip, env);
	while (hadik->arg[var.j])
	{
		if (hadik->arg[var.j][0] == '<' || hadik->arg[var.j][0] == '>')
		{
			a = 1;
			ft_redirection_cmd(hadik->arg, pip, env, &var);
		}
		else
			ft_pipe_cmd(hadik->arg[var.j], pip, env, &var);
		var.j++;
		if (a == 1)
		{
			var.j++;
			a = 0;
		}
	}
	waitpid(var.last_cmd, &var.ext_status, 0);
	var.ext_status = WEXITSTATUS(var.ext_status);
	close(var.save);
}

void	ft_execute_last_one(char *av, int *pip, char **env)
{
	char	**cmd;
	char	*fp;
	int		i;

	cmd = ft_split(av, ' ');
	fp = ft_search_path(cmd[0], env, pip);
	if (!fp)
	{
		write(2, "bash: command not found: ", 25);
		i = 0;
		while (cmd[0][i])
			write(2, &cmd[0][i++], 1);
		write(2, "\n", 1);
		ft_exit(pip);
	}
	close(pip[1]);
	execve(fp, cmd, env);
	ft_exit(pip);
}

void	ft_cmd_to_cmd(t_exct *hadik, char **array)
{
	// int	id;

	// id = fork()
	ft_cmd_loop(hadik, array);
}
