/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:15:57 by sslaoui           #+#    #+#             */
/*   Updated: 2024/08/02 11:42:36 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset(t_list **av, t_exct *lst)
{
	if (ft_search_val(*av, lst->args[1]))
	{puts("sd");
		ft_delete_val(lst->args[1], av);
	}
	else
		return ;
}