/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:15:16 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/25 01:19:37 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_home(t_list *av)
{
	t_list	*tmp;
	t_list	*tmp2;
	char	*val;
	int	i;

	val = NULL;
	i = 0;
	tmp = ft_search_val(av, "HOME=");
	if (!tmp)
	{
		write(2, "bash: cd: HOME not set\n", 24);
		return;
	}
	if (chdir(tmp->content) == -1)
	{
		perror("error cd ");
		return;
	}
	tmp2 = ft_search_val(av, "PWD=");
	ft_modify_val_cd(tmp2, val, tmp->content);
	// system("pwd");
	return ;
}

void	cd_path(t_exct *av, t_list *ar)
{
	// char
	// if (getcwd())
	while (ar)
	{
		if (ft_strncmp(ar->name, "PATH=", 6) == 0)
			break;
		ar = ar->next;
	}
	if (chdir(av->args[0]) == -1)
	{
		perror("error cd ");
		return ;
	}
	system("pwd");
}

void	cd(char **arg, t_exct *a, t_list *av)
{
	int	i;
	int	j;

	arg = NULL;
	i = 0;
	j = 0;
	if (!a->args[0])
	{
		cd_home(av);
		return ;
	}
	else
		cd_path(a, av);
}
