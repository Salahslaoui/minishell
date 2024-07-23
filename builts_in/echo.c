/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 03:44:16 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/15 05:42:06 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(char **arg, char **opt)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;

	while (arg[i])
	{
		if (ft_strncmp(arg[i], "-n", 2) == 0)
			j = 1;
		i++;
	}
	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-' && arg[i][1] == 'n')
			i++;
		else
		{
			printf("%s", arg[i]);
			if (arg[i + 1])
				printf(" ");
			else if (!arg[i + 1] && j == 0)
				printf("\n");
			i++;
		}
	}
}
