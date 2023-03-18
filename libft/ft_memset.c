/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:19:24 by marai             #+#    #+#             */
/*   Updated: 2022/12/10 15:06:55 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
