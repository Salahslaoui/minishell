/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:09:27 by sslaoui           #+#    #+#             */
/*   Updated: 2023/11/16 19:25:26 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;
	size_t			i;

	a = (unsigned char)c;
	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == a)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
