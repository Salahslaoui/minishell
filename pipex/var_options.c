/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 04:24:34 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/20 21:01:58 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"

void	ft_var_init(t_detail *var)
{
	var->i = 0;
	var->j = 0;
	var->save = 0;
}

void	ft_pipe_cmd(char *av, int *pip, char **env, t_detail *var)
{
	pipe(pip);
	var->id = fork();
	if (var->id != 0 && var->j == var->i)
		var->last_cmd = var->id;
	if (var->save != 0)
		close(var->save);
	if (var->j == 1 && var->id == 0)
		ft_first_one(av , pip, env);
	if (var->j > 1 && var->j < var->i && var->id == 0)
		ft_cmd_execute(av, pip, env);
	else if (var->j == var->i && var->id == 0)
		ft_execute_last_one(av, pip, env);
	var->save = dup(pip[0]);
	close(pip[0]);
	dup2(var->save, 0);
	close(pip[1]);
}

void	ft_redirection_cmd(char **av, int *pip, char **env, t_detail *var)
{
	int	fd;

	pip = NULL;
	env = NULL;
	if (av[var->j][0] == '<')
	{
		fd = open(av[var->j + 1], O_RDONLY, 0777);
		dup2(fd, 0);
	}
	else if (av[var->j][0] == '>')
	{
		fd = open(av[var->j + 1], O_WRONLY | O_TRUNC, 0777);
		dup2(fd, 1);
	}
	else if (av[var->j][0] == '>' && av[var->j][1] == '>')
	{
		fd = open(av[var->j + 1], O_WRONLY | O_APPEND, 0777);
		dup2(fd, 1);
	}
}
