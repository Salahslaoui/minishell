/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:55:43 by sslaoui           #+#    #+#             */
/*   Updated: 2023/12/07 10:56:01 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_min_int(int n, unsigned int count, char *str)
{
	int	i;

	if (n == 0)
		str[0] = '0';
	else if (n == -2147483648)
	{
		i = count - 1;
		while (i > 0)
		{
			str[i] = -(n % 10) + '0';
			n /= 10;
			i--;
		}
		str[0] = '-';
	}
	return (str);
}

static char	*ft_convert(int n, unsigned int count, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n)
	{
		str[--count] = ((n % 10) + '0');
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		num;

	num = n;
	if (n == 0)
		count = 1;
	else
		count = 0;
	if (n < 0)
		count++;
	while (num)
	{
		num /= 10;
		count++;
	}
	str = (char *)malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (n == -2147483648 || n == 0)
		str = ft_min_int(n, count, str);
	else
		str = ft_convert(n, count, str);
	return (str);
}
