/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:30:17 by marai             #+#    #+#             */
/*   Updated: 2022/10/10 16:18:02 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	j = 0;
	if (!dest && src && size == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dest);
	if (size <= dstlen)
		return (size + ft_strlen(src));
	i = dstlen;
	while (j + dstlen + 1 < size && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dstlen + ft_strlen(src));
}

// #include<libc.h>
// int main()
//{
// char *dst1 = calloc(100, sizeof(char));
// char *dst2 = calloc(100, sizeof(char));
// char *src1 = calloc(100, sizeof(char));
// char *src2 = calloc(100, sizeof(char));
// ft_strlcat(dst1, "hello", 100);
// strlcat(dst2, "hello", 100);
// for (int i = 0; i < 99; i++)
// {
// 	src1[i] = i + 1;
// 	src2[i] = i + 1;
// }
// printf("aaa%lu", strlen(src1));
// // printf("%s %s\n",dst1, src1);
// printf("%s %s\n",dst2, src2);
//printf("%lu\n", ft_strlcat(dst1, src1, 0));

// printf("%lu\n", strlcat("watashi", "hade", 2));
// printf("%lu\n", strlcat("watashi", "hare", 3));
// printf("%lu\n", strlcat("watashi", "hare", 4));
//}