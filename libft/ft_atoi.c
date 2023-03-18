/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:24:08 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 06:50:25 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_over(int sign, unsigned long ans, char c)
{
	unsigned long	tmp;

	if (sign == 1)
		c++;
	tmp = LONG_MAX / 10;
	if (tmp < ans || (tmp == ans && LONG_MAX % 10 + 1 < c - '0'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	ans;
	int				sign;
	int				i;

	ans = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && ft_check_over(sign, ans, str[i]))
			return ((int)LONG_MAX);
		if (sign == -1 && ft_check_over(sign, ans, str[i]))
			return ((int)LONG_MIN);
		ans = 10 * ans + (str[i] - '0');
		i++;
	}
	return (ans * sign);
}
