/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:59:13 by sslaoui           #+#    #+#             */
/*   Updated: 2023/12/09 10:34:12 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max;

	max = count * size;
	if (count == 0 || size == 0)
		return (malloc(0));
	if (max / count != size)
		return (NULL);
	ptr = malloc(max);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, max);
	return (ptr);
}
