/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:13:24 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 06:51:14 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	temp1 = (unsigned char *)buf1;
	temp2 = (unsigned char *)buf2;
	if (temp1 <= temp2)
	{
		while (i < n)
		{
			temp1[i] = temp2[i];
			i++;
		}
	}
	else
	{
		while (0 < n--)
			temp1[n] = temp2[n];
	}
	return (buf1);
}

/*
#include <string.h>
int	main(void)
{
	printf("%s\n", memmove(NULL,NULL,0));
	printf("%s\n", ft_memmove(NULL,NULL,0));
}
*/