/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:10:20 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/26 20:26:55 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"
#include "../minishell.h"

void	ft_first_one(char **av, int *pip, char **env, t_detail *var)
{
	char	**cmd;
	char	*fp;
	int		i;

	printf("%d\n", var->fd);
	i = var->j;
	cmd = ft_split(av[i], ' ');
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
	// if (red)
	// 	ft_
	if (dup2(pip[1], 1) == -1)
		ft_exit(pip);
	execve(fp, cmd, env);
	ft_exit(pip);                                                                                                                                                                                                                                          
}

void	ft_cmd_execute(char **av, int *pip, char **env, t_detail *var)
{
	char	**cmd;
	char	*fp;
	int		i;

	i = var->j;
	cmd = ft_split(av[0], ' ');
	fp = ft_search_path(cmd[0], env, pip);
	// printf("%s\n", av[0]);
	// close(pip[0]);
	// if (av[i] &&  (av[i + 1][0] == 'b' || av[i + 1][0] == 'a'))
	// {
	// 	while (av[i] && av[i + 1])
	// 	{
	// 		if (av[i + 1][0] != 'b' || av[i + 1][0] != 'a')
	// 			ft_redirection_cmd(av, pip, i, var);
	// 		i++;
	// 	}
	// 		if (av[i][0] == 'b')
	// 		{
	// 			write(2, "bash: syntax error near unexpected token `newline'\n", 52);
	// 			ft_exit(pip);
	// 			exit(0);
	// 		}
	// }
	if (dup2(pip[1], 1) == -1)
		ft_exit(pip);
	if (!fp)
	{
		write(2, "bash: command not found: ", 25);
		i = 0;
		while (cmd[0][i])
			write(2, &cmd[0][i++], 1);
		write(2, "\n", 1);
		ft_exit(pip);
	}
	execve(fp, cmd, env);
	ft_exit(pip);
}

void	ft_execute_one_cmd(t_exct *av, int *pip, char **env, t_detail *var)
{
	char	**cmd;
	char	*fp;
	int		i;
	// var = NULL;
	// env = NULL;

	// pip[0] = 0;
	// pip[1] = 0;
	if (av->red)
		ft_redirection_cmd(av, pip, var);
	cmd = ft_split(av->args[0], ' ');
	fp = ft_search_path(cmd[0], env, pip);
	// if (av[i] && (av[i][0] == 'b' || av[i][0] == 'a'))
	// {
	// 	write(1, "ss", 2);
	// 	ft_redirection_cmd(av, pip, i, var);
	// 	exit(0);
	// }
	// if (!fp)
	// {
	// 	write(2, "bash: command not found: ", 25);
	// 	i = 0;
	// 	while (cmd[0][i])
	// 		write(2, &cmd[0][i++], 1);
	// 	write(2, "\n", 1);
	// 	ft_exit(pip);
	// }
	execve(fp, cmd, env);
	ft_exit(pip);
}

void	ft_cmd_loop(t_exct *av, char **env)
{
	t_detail	var;
	t_exct		*tmp;
	int	pip[2];
	int		a;

	tmp = av;
	// env = NULL;
	// pip[0] = 0;
	// pip[1] = 0;
	a = 0;
	ft_var_init(&var);
	while (tmp)
	{
		var.i++;
		tmp = tmp->next;
	}
	if (var.i == 1)
	{
		if (fork() == 0)
			ft_execute_one_cmd(av, pip, env, &var);
	}
	else
	{
		while (var.j < var.i + 1 && av)
		{
			// printf("%s\n", av->args[0]);
			ft_pipe_cmd(av, pip, env, &var);
			var.j++;
			av = av->next;
		}
	}
	// waitpid(var.last_cmd, &var.ext_status, 0);
	// /*
	// WIFEXITED() -> if true it means that the process exited with a call to exit()
	// */
	// var.ext_status = WEXITSTATUS(var.ext_status);
	close(var.save);
}

void	ft_execute_last_one(char **av, int *pip, char **env, t_detail *var)
{
	char	**cmd;
	char	*fp;
	int		i;

	i = var->j;
	cmd = ft_split(av[0], ' ');
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
	// if (av[i] && (av[i][0] == 'b' || av[i][0] == 'a'))
	// 	ft_redirection_cmd(av, pip, i, var);
	execve(fp, cmd, env);
	ft_exit(pip);
}

void	ft_cmd_to_cmd(t_exct *hadik, char **env)
{
	// int	id;

	// id = fork()
	ft_cmd_loop(hadik, env);
}
