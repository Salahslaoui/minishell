/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:53:43 by sslaoui           #+#    #+#             */
/*   Updated: 2023/12/07 10:53:06 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new_lst;
	t_list	*node;

	p = lst;
	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (p)
	{
		node = ft_lstnew(NULL);
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		node->content = f(p->content);
		ft_lstadd_back(&new_lst, node);
		p = p->next;
	}
	return (new_lst);
}
