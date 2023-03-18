/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:05:21 by marai             #+#    #+#             */
/*   Updated: 2022/12/10 15:06:41 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	temp1 = (unsigned char *)buf1;
	temp2 = (unsigned char *)buf2;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (buf1);
}

/*
#include <string.h>
int	main(void)
{
	printf("%s\n", memcpy(NULL,NULL,0));
	printf("%s\n", ft_memcpy(NULL,NULL,0));
}
*/