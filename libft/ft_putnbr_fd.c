/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:42:05 by marai             #+#    #+#             */
/*   Updated: 2022/10/15 14:44:23 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;
	int		sign;
	int		divnum;

	sign = 1;
	num = '0';
	divnum = 1000000000;
	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	if (n == 0)
		divnum = 1;
	while (n / divnum == 0 && n != 0)
		divnum /= 10;
	while (divnum != 0)
	{
		num = sign * (n / divnum) + '0';
		write(fd, &num, 1);
		n = n - (n / divnum) * divnum;
		divnum /= 10;
	}
}
