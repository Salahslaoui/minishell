/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:10:13 by sslaoui           #+#    #+#             */
/*   Updated: 2023/11/16 17:49:43 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;

	i = ft_strlen(s);
	a = (char )c;
	while (i > 0 && s[i] != a)
		i--;
	if (s[i] == a)
		return ((char *)&s[i]);
	if (i < 0)
		return (NULL);
	return (0);
}
