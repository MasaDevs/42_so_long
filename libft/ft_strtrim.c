/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:03:47 by marai             #+#    #+#             */
/*   Updated: 2022/12/10 15:08:17 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	end;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[front]) != NULL && s1[front] != '\0')
		front++;
	while (ft_strchr(set, s1[end]) != NULL && 0 < end)
		end--;
	if (end == 0)
	{
		dst = malloc(sizeof(char) * 1);
		dst[0] = '\0';
		return (dst);
	}
	else if (end < front)
		return (NULL);
	dst = malloc(sizeof(char) * (end - front + 2));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, &s1[front], end - front + 2);
	return (dst);
}

/*
int	main(void)
{
	char	arr1[];
	char	arr2[];
	char	*arr;

	arr1[] = "kzkzkzkzk";
	arr2[] = "kz";
	arr = ft_strtrim(arr1, arr2);
	printf("%s\n", arr);
	free(arr);
	return (0);
}
*/
