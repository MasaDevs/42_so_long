/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:36:51 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 06:50:44 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		temp;
	const unsigned char	*src;
	size_t				i;

	i = 0;
	temp = (unsigned char)c;
	src = (const unsigned char *)s;
	while (i < n)
	{
		if (src[i] == temp)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
