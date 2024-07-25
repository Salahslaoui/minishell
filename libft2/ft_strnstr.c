/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:50:02 by sslaoui           #+#    #+#             */
/*   Updated: 2023/12/02 09:24:45 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (haystack == NULL && len == 0)
		return (NULL);
	else if (len == 0 && needle[0] == '\0')
		return ((char *)haystack);
	else if (ft_strcmp(haystack, needle) == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len >= ft_strlen(needle))
	{
		j = 0;
		while (haystack[j] == needle[j] && j < ft_strlen(needle))
			j++;
		if (j == ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
