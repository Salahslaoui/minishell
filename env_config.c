/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:22:44 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/28 12:46:13 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_modify_val(t_list *av, char *val, char *arg) // =salama
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
		i++;
	free(av->content);
	av->content = NULL;
	val = ft_strdup(&arg[i]);
	av->content = val;
	// printf("%s\n", val);
	// i = i - j - 1;
	// j = 0;
	// while (arg[i])
	// {
	// 	av->content[j] = arg[i];
	// 	j++;
	// 	i++;
	// }	
}

void	ft_add_val(char *val, t_list *av, char *var)
{
	t_list	*tmp;
	int		i;

	i = 0;
	// while (av->next)
	// 	av = av->next;
	tmp = ft_lstnew(val);
	// tmp->name = var;
	if (!val)
		val = NULL;
	tmp->content = val;
	printf("%s\n", tmp->content);
	ft_lstadd_back(&av, tmp);
	// av->next = tmp;
	// av = av->next;
	// printf("%s\n", av->content);
	// ft_lstadd_back(&av, tmp);
}

char	**list_t_array(t_list *av)
{
	t_list	*tmp;
	char	**arr;
	// char	*ptr;
	int		i;

	tmp = av;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = av;
	arr = malloc(sizeof(char *) * (i + 1));
	i = 0;
	if (!arr)
		return (NULL);
	while (tmp)
	{
		arr[i] = ft_strjoin(tmp->name, tmp->content);
		tmp = tmp->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	create_var(t_list *av, char *arg)
{
	t_list	*tmp;
	char	*var;
	char	*val;
	int		i;
	int		j;
	int		a;

	val = NULL;
	tmp = av;
	a = 0;
	i = 0;
	j = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	var = malloc(i + 1);
	i = 0;
	while (arg[i] != '=')
	{
		var[i] = arg[i];
		i++;
	}
	// if (arg[i] == '=')
	// {
	// 	i++;
	// 	while (arg[i++])
	// 		j++;
	// 	val = malloc(j + 1);
	// 	i = i - j - 1;
	// 	j = 0;
	// 	while (arg[i])
	// 	{
	// 		val[j] = arg[i];
	// 		j++;
	// 		i++;
	// 	}
	// }	
	// else
	// 	val = NULL;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, var, ft_strlen(var)) == 0)
		{
			a = 1;
			ft_modify_val(tmp, val, arg);
		}
		tmp = tmp->next;
	}
	if (a == 0)
		ft_add_val(val, av, var);
}
