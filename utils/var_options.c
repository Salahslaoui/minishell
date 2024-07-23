/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 04:24:34 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/21 20:30:02 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"

void	ft_var_init(t_detail *var)
{
	var->i = 0;
	var->j = 1;
	var->fd = 0;
	var->save = 0;
}

void	ft_pipe_cmd(char **av, int *pip, char **env, t_detail *var)
{
	pipe(pip);
	var->id = fork();
	if (var->id != 0 && var->j == var->i)
		var->last_cmd = var->id;
	if (var->save != 0)
		close(var->save);
	if (var->j == 1 && var->id == 0 && av[var->j][0] != 'b')
		ft_first_one(av , pip, env, var);
	if (var->j > 1 && var->j < var->i && var->id == 0)
	{
		if (av[var->j][0] != 'b' && av[var->j][0] != 'a')
			ft_cmd_execute(av, pip, env, var);
	}
	if (var->j == var->i && var->id == 0 && av[var->j][0] != 'b')
		ft_execute_last_one(av[var->j], pip, env);
	// if (av[var->j][0] == 'b' || av[var->j][0] == 'a')
	// 	ft_redirection_cmd(av, pip, var->j, var);
	var->save = dup(pip[0]);
	close(pip[0]);
	dup2(var->save, 0);
	close(pip[1]);
}

void	ft_redirection_cmd(char **av, int *pip, int i, t_detail *var)
{
	// char	**cmd;
	// char	*fp;
	// int		fd;

	pipe(pip);
	if (av[var->j][0] == 'a')
	{
		var->fd = open(av[var->j + 1], O_RDONLY, 0777);
		dup2(var->fd, 0);
	}
	else if (av[i][0] == 'b')
	{
		if (var->fd)
			close(var->fd);
		var->fd = open(av[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(var->fd, 1);
	}
	else if (av[var->j][0] == '>' && av[var->j][1] == '>')
	{
		var->fd = open(av[var->j + 1], O_WRONLY | O_APPEND, 0777);
		dup2(var->fd, 1);
	}
	// if (av[var->j - 1])
	// {	
	// 	if (fork() == 0)
	// 	{
	// 		printf("%d", 5);
	// 		close(pip[1]);
	// 		dup2(pip[0], 0);
	// 		fp = ft_search_path(av[var->j - 1], env, pip);
	// 		cmd = ft_split(av[var->j - 1], ' ');
	// 		execve(fp, cmd, env);
	// 	}
	// }
}

// void	f
