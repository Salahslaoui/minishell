/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:32:12 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/23 10:59:40 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

t_exct	*ft_lstnew_hadik(char *str)
{
	t_exct	*lst;

	str = NULL;
	lst = malloc(sizeof(t_exct));
	if (!lst)
		return (NULL);
	lst->cmd = NULL;
	lst->arg = NULL;
	lst->opt = NULL;
	lst->pip = 0;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_hadik(t_exct **lst, t_exct *new)
{
	t_exct	*p;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

void	ft_free(char **my_env)
{
	int	i;

	i = 0;
	while (my_env[i])
	{
		free(my_env[i]);
		i++;
	}
	free(my_env);
}

void	ft_name_env(t_list *n, char *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i] != '=')
		i++;
	i++;
	n->name = malloc(i + 1);
	while (j < i)
	{
		n->name[j] = env[j];
		j++;
	}
	n->name[j] = '\0';
}

void	ft_val_name(t_list *n, char *env)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	while (env[i] != '=')
		i++;
	while (env[j])
		j++;
	a = j - i;
	n->content = malloc(a + 1);
	j = 0;
	i++;
	while (env[i])
		n->content[j++] = env[i++];
	n->content[j] = '\0';
}

t_list	*ft_set_env(char **env)
{
	t_list	*hrba;
	t_list	*n;
	// char	
	int	i;

	i = 0;
	hrba = NULL;
	while (env[i])
	{
		n = ft_lstnew(env[i]);
		ft_name_env(n, env[i]);
		ft_val_name(n, env[i]);
		ft_lstadd_back(&hrba, n);
		i++;
	}
	return (hrba);
}

t_list	*ft_search_var(t_list *av, char *target)
{
	t_list	*tmp;

	tmp = av;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, target, ft_strlen(target)) == 0)
			return(tmp);
		tmp = tmp->next;
	}
	return (NULL);
}


void	ft_delete_val(char	*val, t_list **av)
{
	t_list		*current;
	t_list		*previous;

	previous = 0;
	current = *av;
	while (current)
	{
		if (ft_strncmp(current->name, val, ft_strlen(val)) == 0)
		{
			if (previous == 0)
			{
				*av = current->next;
			}
			else
				previous->next = current->next;
			free(current);
			break;
		}
		previous = current;
		current = current->next;
	}
}

t_list	*ft_search_val(t_list *av, char *val)
{
	t_list	*tmp;

	tmp = av;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, val, ft_strlen(val)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	fill_struct(t_exct **hadik, char *arr)
{
	// t_exct	*lst;
	// char	**sp;
	// char	**fp;
	// int		i;
	// int		j;
	// int		k;

	// lst = NULL;
	// hadik->pip = 0;
	// k = 0;
	// i = 0;
	// j = 0;
	// sp = ft_split(arr, '|');
	// while (sp[i])
	// {
	// 	fp = ft_split(sp[i], ' ');
	// 	hadik = ft_lstnew_hadik(fp[i]);
	// 	hadik->cmd = fp[0];
	// 	if(fp[1])
	// 		hadik->arg = fp;
	// 	printf("%s\n", hadik->arg[0]);
	// 	ft_lstadd_back_hadik(&lst, hadik);
	// 	i++;
	// }
	*hadik = ft_lstnew_hadik(arr);
	(*hadik)->cmd = ft_strdup("cd");
	(*hadik)->arg = malloc(sizeof(char *) * 3);
	(*hadik)->arg[0] = ft_strdup("/Library/Scripts/42");
	(*hadik)->arg[1] = ft_strdup("dasdsaf");
	(*hadik)->arg[2] = NULL;
	(*hadik)->opt = malloc(sizeof(char *) * 3);
	(*hadik)->opt[0] = ft_strdup("-la");
	(*hadik)->opt[1] = ft_strdup("-ds");
	(*hadik)->opt[2] = NULL;
	// printf("%s\n", hadik->cmd);
}

char	**fill_sp(t_exct *hadik, char **sp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (hadik->cmd)
	{
		sp[i] = hadik->cmd;
		i++;
	}
	while (hadik->arg[j])
	{
		sp[i] = hadik->arg[j];
		i++;
		j++;
	}
	j = 0;
	while (hadik->opt[j])
	{
		sp[i] = hadik->opt[j];
		i++;
		j++;
	}
	sp[i] = NULL;
	return (sp);
}

char	**ft_struct_to_av(t_exct *hadik)
{
	char	**sp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (hadik->cmd)
		i++;
	while (hadik->arg[j++])
		i++;
	j = 0;
	while (hadik->opt[j++])
		i++;
	sp = malloc((sizeof(char *)) * (i + 1));
	sp = fill_sp(hadik, sp);
	return (sp);
}

int main(int ac, char **argv, char  **env)
{
	(void)ac;
	(void)argv;
	// t_list	*av;
	t_exct	*hadik;
	char	*arr;
	char	**sp;
	char	**array;
	int		i;

	env = NULL;
	arr = NULL;
	array = NULL;
	i = 0;
	// av = ft_set_env(env);
	// while(1)
	// {
		// array = list_t_array(av);
	// 	if (ft_strlen(arr) > 0)
	// 		add_history(arr);
	// 	if (ft_strcmp("cd", hadik.cmd) == 0)
	// 		cd(NULL, &hadik, av);
	// }
		// arr = readline("akoutate>");
		// if (!arr)
		// {
		// 	printf("exit\n");
		// 	exit(1);
		// }
		// sp = ft_struct_to_av(&hadik);
		fill_struct(&hadik, arr);
		sp = ft_struct_to_av(hadik);
		ft_cmd_to_cmd(sp, array);
	// 	arr = hadik->cmd;
	// printf("%s\n", hadik->arg[0]);
	// while (hadik)
	// {
	// 	printf("%s\n", hadik->cmd);
	// 	hadik = hadik->next;
	// }
	// ss = ft_search_var(av, "dasdas");
	// create_var(av, "TMPDIR=");
	// ss = ft_search_val(av, "GIT_ASKPASS");
	// while (av)
	// {
		// printf("%s  %s\n", ss->name, ss->content);
	// 	av = av->next;
	// }
}
