/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:07:47 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/05 04:11:37 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../minishell.h"

void	ft_exit1(char *av, int *pip)
{
	int		i;
	char	c;

	i = 0;
	c = 8;
	write(1, "zsh: No such file or directory: ", 32);
	while (av[i])
		write(1, &av[i++], 1);
	write(1, "\n", 1);
	close(pip[0]);
	close(pip[1]);
	exit(0);
}

void	ft_close(int *pip)
{
	close(pip[0]);
	close(pip[1]);
}

// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	int		pip[2];
// 	int		id;

// 	if (pipe(pip) == -1)
// 		exit(0);
// 	id = fork();
// 	if (id < 0)
// 		exit(0);
// 	if (id == 0)
// 		ft_execute_cmd1(av, pip, env);
// 	id = fork();
// 	if (id == 0)
// 	{
// 		wait(0);
// 	ft_execute_cmd2(av, pip, env);
// 	}
// 	ft_close(pip);
// 	wait(0);
// 	ft_close(pip);
// 	wait(0);
// }

int main(int ac, char **av, char **env)
{
	(void)ac;
	int	l;

	l = dup(0);
	ft_cmd_to_cmd(av, env);
	while(wait(0) != -1);
	dup2(l, 0);
	close(l);
	// while (1);
}
