/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 03:20:41 by marai             #+#    #+#             */
/*   Updated: 2022/12/31 00:12:34 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_base(long long nbr, char *base, ssize_t sign)
{
	long long	keta;
	long long	tmp;
	ssize_t		baselen;
	ssize_t		len;

	keta = 1;
	len = 0;
	tmp = nbr * sign;
	baselen = ft_strlen(base);
	while (keta <= tmp / (long long)baselen)
		keta *= (long long)baselen;
	while (keta != 0)
	{
		write(1, &base[(nbr / keta) * sign], 1);
		nbr = (nbr % keta) * sign;
		keta = keta / (long long)baselen;
		len++;
	}
	return (len);
}

ssize_t	ft_putnbr_ptr(uintptr_t nbr, char *base, ssize_t sign)
{
	uintptr_t	keta;
	uintptr_t	tmp;
	ssize_t		len;
	ssize_t		baselen;

	keta = 1;
	len = 0;
	tmp = nbr * sign;
	baselen = ft_strlen(base);
	while (keta <= tmp / (uintptr_t) baselen)
		keta *= (uintptr_t)baselen;
	while (keta != 0)
	{
		write(1, &base[(nbr / keta) * sign], 1);
		nbr = (nbr % keta) * sign;
		keta = keta / (uintptr_t) baselen;
		len++;
	}
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}
