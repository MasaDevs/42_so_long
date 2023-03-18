/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:05:51 by marai             #+#    #+#             */
/*   Updated: 2022/10/11 08:20:47 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <string.h>
int	main(void)
{
	char	dst[];
	char	dst1[];
	char	src[];
	char	src1[];

	dst[] = "hello world!";
	dst1[] = "hello world!";
	src[] = "okgoogle";
	src1[] = "okgoogle";
	printf("%lu\n", strlcpy(dst, src, 0));
	printf("%zu\n", ft_strlcpy(dst1, src1, 0));
	printf("%s\n", dst);
	printf("%s\n", dst1);
}

*/