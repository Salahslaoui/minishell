/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:23:21 by sslaoui           #+#    #+#             */
/*   Updated: 2024/08/02 11:42:11 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_builts_in(char *arr, t_exct *ex, t_list **av)
{
	if (ft_strcmp(arr, "env") == 0)
		env(*av);
	if (ft_strcmp(arr, "export") == 0)
		export(*av, ex);
	if (ft_strcmp(arr, "unset") == 0)
		unset(av, ex);
}

void	env(t_list *av)
{
	while (av && av->content)
	{
		printf("%s=%s\n", av->name, av->content);
		av = av->next;
	}
}