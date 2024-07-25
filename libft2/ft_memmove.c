/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:45:15 by sslaoui           #+#    #+#             */
/*   Updated: 2023/11/24 21:02:47 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*ptr;
	const char		*s;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	s = (const char *) src;
	ptr = (char *) dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	else if (dst > src)
	{
		while (len > 0)
		{
			ptr[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}
