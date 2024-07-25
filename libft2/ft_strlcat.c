/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:25:08 by sslaoui           #+#    #+#             */
/*   Updated: 2023/11/21 11:12:39 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ld;
	size_t	a;
	size_t	i;

	a = ft_strlen(src);
	if (!dstsize)
		return (a);
	if (!src)
		return (dstsize);
	ld = ft_strlen(dst);
	i = 0;
	if (dstsize <= ld)
		return (a + dstsize);
	while (i < dstsize - ld - 1 && src[i] != '\0')
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (ld + i);
}
