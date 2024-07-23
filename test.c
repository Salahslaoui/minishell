/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 05:20:18 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/20 11:42:04 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(void)
{
	write(2, "syntax error\n", 13);
	exit(1);
}

// void	check_cmd(t_exct *inp, char *av)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (av[i])
// 		if (av[i++] == '|')
// 			j++;
// 	if (j = 1)
// 		ft_
// }

// void	ft_execution(char *av, char **env)
// {
// 	t_exct inp;

// 	inp.cmd = "ls";
// 	ft_set_env(env);
// 	ft_check_cmd(&inp, av);
// }

int	ft_check_space(char *av)
{
	int	i;

	i = 0;
	while (av[i] == ' ' || av[i] == '\t')
		i++;
	if (i == ft_strlen(av) && ft_strlen(av) > 0)
		return (1);
	return (0);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char	*inp;

	while(1)
	{
		inp = readline("minishell>");
		if (!inp)
		{
			printf("exit\n");
			exit(1);
		}
		if (ft_strlen(inp) > 0)
			add_history(inp);
		// ft_execution(inp, env);
	}
	// if (!check_arg(av))
	// 	ft_exit();
}