 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 04:24:34 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/26 09:54:24 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"

void	ft_exit_fd(int	*pip, t_exct *av, int i)
{
	int	j;

	j = 0;
	close(pip[0]);
	close(pip[1]);
	if (access(av->red[i + 1], F_OK) == -1)
	{
		write(2, "bash: ", 7);
		while (av->red[i + 1][j])
			write(2, &av->red[i + 1][j++], 1);
		write(2, ": No such file or directory\n", 29);
		exit(1);
	}
	else if (av->red[i][0] == '<' && access(av->red[i + 1], R_OK) == -1)
	{
		write(2, "bash: ", 7);
		while (av->red[i + 1][j])
			write(2, &av->red[i + 1][j++], 1);
		write(2, ": Permission denied\n", 21);
		exit(1);
	}
}

void	ft_var_init(t_detail *var)
{
	var->i = 0;
	var->j = 1;
	var->fd = 0;
	var->save = 0;
}

void	ft_pipe_cmd(t_exct *av, int *pip, char **env, t_detail *var)
{
	pipe(pip);
	var->id = fork();
	if (var->id == 0 && av->red)
		ft_redirection_cmd(av, pip, var);
	if (var->id != 0 && var->j == var->i)
		var->last_cmd = var->id;
	if (var->save != 0)
		close(var->save);
	// printf("%d\n", var->j);
	// if (var->j == 0 && var->id == 0)
	// 	ft_first_one(av->args , pip, env, var);
	if (var->j > 0 && var->j < var->i && var->id == 0)
			ft_cmd_execute(av->args, pip, env, var);
	if (var->j == var->i && var->id == 0)
		ft_execute_last_one(av->args, pip, env, var);
	var->save = dup(pip[0]);
	close(pip[0]);
	dup2(var->save, 0);
	close(pip[1]);
}

void	ft_redirection_cmd(t_exct *av, int *pip, t_detail *var)
{
	int	i;

	i = 0;
	// pipe(pip);
	// fprintf(stderr, "REACHED: %s\n", av->red[i + 1]);
	while (av->red[i])
	{
		if (av->red[i][0] == '<' && av->red[i + 1])
		{
			var->fd = open(av->red[i + 1], O_RDONLY, 0644);
			dup2(var->fd, 0);
		}
		else if (av->red[i][0] == '>' && av->red[i + 1])
		{
			if (av->red[i][1] && av->red[i][1] == '>')
				var->fd = open(av->red[i + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
			else
				var->fd = open(av->red[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
			dup2(var->fd, 1);
		}
		if (var->fd == - 1)
			ft_exit_fd(pip, av, i);
		i += 2;
	}
}

// void	f
