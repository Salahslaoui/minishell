/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:54:46 by sslaoui           #+#    #+#             */
/*   Updated: 2023/11/25 06:04:50 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!lst || !*lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		*lst = (*lst)->next;
		ft_lstdelone(p, del);
		p = *lst;
	}
	*lst = NULL;
}
