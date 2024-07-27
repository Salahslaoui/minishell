/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:20:06 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/25 19:55:51 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../minishell.h"

void	ft_exit(int *pip)
{
	close(pip[1]);
	close(pip[0]);
	exit(EXIT_FAILURE);
}

char	*ft_search_cmd(char *first_path, char *av, int *pip)
{
	char	**paths;
	char	*str;
	char	*ptr;
	int		i;

	if (av[0] == '/' && access(av, F_OK) == -1)
		ft_exit1(av, pip);
	ptr = ft_strjoin("/", av);
	paths = ft_split(first_path, ':');
	i = 0;
	while (paths[i])
	{
		str = ft_strjoin(paths[i], ptr);
		free(paths[i]);
		if (access(str, F_OK) == 0)
		{
			while (paths[i++])
				free(paths[i]);
			return (free(ptr), free(paths), str);
		}
		free(str);
		i++;
	}
	return (free(ptr), free(paths), NULL);
}

char	*ft_search_path(char *av, char **env, int *pip)
{
	char	*str;
	char	*ptr;
	int		i;

	// if (access(av, F_OK) == 0)
	// 	return (av);
	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A')
			if (env[i][2] == 'T' && env[i][3] == 'H')
				break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	str = env[i];
	str = str + 5;
	ptr = ft_search_cmd(str, av, pip);
	return (ptr);
}

void	ft_execute_cmd1(char **av, int *pip, char **env)
{
	char	**cmd;
	char	*fp;
	int		infile;
	int		i;

	cmd = ft_split(av[0], ' ');
	fp = ft_search_path(cmd[0], env, pip);
	if (!fp)
	{
		write(2, "zsh: command not found: ", 24);
		i = 0;
		while (cmd[0][i])
			write(2, &cmd[0][i++], 1);
		ft_exit(pip);
	}
	infile = open(av[1], O_RDWR);
	if (infile == -1)
		ft_exit1(av[1], pip);
	close(pip[0]);
	if (dup2(infile, 0) == -1 || dup2(pip[1], 1) == -1)
		ft_exit(pip);
	execve(fp, cmd, env);
	ft_exit(pip);
}

void	ft_execute_cmd2(char **av, int *pip, char **env)
{
	char	**cmd;
	char	*sp;
	int		outfile;
	int		i;

	cmd = ft_split(av[3], ' ');
	sp = ft_search_path(cmd[0], env, pip);
	if (!sp)
	{
		write(1, "zsh: command not found: ", 24);
		i = 0;
		while (cmd[0][i])
			write(1, &cmd[0][i++], 1);
		ft_exit(pip);
	}
	outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_exit1(av[1], pip);
	close(pip[1]);
	if (dup2(pip[0], 0) == -1 || dup2(outfile, 1) == -1)
		ft_exit(pip);
	execve(sp, cmd, env);
	ft_exit(pip);
}
