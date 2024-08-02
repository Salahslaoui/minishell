/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:10:36 by sslaoui           #+#    #+#             */
/*   Updated: 2024/08/02 12:39:44 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_name_env_1(t_list *n, char *env, int *a)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (env[i] != '=')
		i++;
	if (env[i - 1] && env[i - 1] == '+' && env[i] == '=')
		*a = 1;
	if (env[i - 1] && env[i - 1] == '+')
		i--;
	i++;
	n->name = malloc(i + 1);
	while (j < i)
	{
		if (env[k] == '+')
			k++;
		n->name[j] = env[k];
		j++;
		k++;
	}
	n->name[j] = '\0';
}

void	ft_swap(t_list *tmp, t_list *previous)
{
	char	*name;
	char	*content;

	name = previous->name;
	content = previous->content;
	previous->name = tmp->name;
	previous->content = tmp->content;
	tmp->name = name;
	tmp->content = content;
}

void	ft_add_env(t_exct *lst, t_list *av)
{
	t_list	*tmp;
	t_list	*ptr;
	char	*save;
	int	i;
	int	a;

	// tmp = av;
	a = 0;
	i = 1;
	while (lst->args[i])
	{
		printf("%s\n", lst->args[i]);
		tmp = ft_lstnew(lst->args[i]);
		ft_name_env_1(tmp, lst->args[i], &a);
		ft_val_name(tmp, lst->args[i]);
		ptr = ft_search_val(av, tmp->name);
		if (tmp->name && ptr)
		{
			if (a == 1)
			{
				save = ptr->content;
				ptr->content = ft_strjoin(ptr->content, tmp->content);
				free(save);
				// free(tmp)
			}
			else
			{
				free(ptr->content);
				ptr->content = tmp->content;
			}
		}
		else
			ft_lstadd_back(&av, tmp);
		i++;
	}
}

void	ft_sort_and_display(t_list *av)
{
	t_list	*tmp;
	t_list	*previous;

	previous = av;
	tmp = av;
	if (tmp->next)
		tmp = tmp->next;
	else
		return ;
	while (tmp)
	{
		while (previous)
		{
			if (strcmp(tmp->name, previous->name) < 0)
				ft_swap(tmp, previous);
			previous = previous->next;
		}
		previous = av;
		tmp = tmp->next;
	}
	while (av)
	{
		printf("declare -x %s\"%s\"\n", av->name, av->content);
		av = av->next;
	}
}

void	export(t_list *av, t_exct *lst)
{
	if (!lst->args[1])
		ft_sort_and_display(av);
	else
		ft_add_env(lst, av);
}
