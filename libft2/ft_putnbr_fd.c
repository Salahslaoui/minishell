/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:32:24 by sslaoui           #+#    #+#             */
/*   Updated: 2023/11/25 06:19:28 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_number(char a, int fd)
{
	if (fd > 0)
		write (fd, &a, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
	{
		write (1, "fd must be > 0", 15);
		return ;
	}
	if (n == -2147483648 && fd > 0)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_write_number('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_write_number(n + '0', fd);
}
