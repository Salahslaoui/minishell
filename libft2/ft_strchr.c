/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:09:42 by sslaoui           #+#    #+#             */
/*   Updated: 2023/12/04 11:52:52 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	i = 0;
	a = (char )c;
	while (s[i] != '\0')
	{
		if (a == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *)&s[i]);
	return (NULL);
}
