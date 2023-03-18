/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:31:59 by marai             #+#    #+#             */
/*   Updated: 2022/10/14 13:36:09 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (size == 0 || count == 0)
	{
		temp = malloc(1);
		if (temp == NULL)
			return (NULL);
		ft_bzero(temp, 1);
	}
	else
	{
		if (SIZE_MAX / size < count)
			return (NULL);
		temp = malloc(size * count);
		if (temp == NULL)
			return (NULL);
		ft_bzero(temp, count * size);
	}
	return (temp);
}

// #include <string.h>
// int main()
// {
// 	int size = 8539;

// 	void * d1 = ft_calloc(size, sizeof(int));
// 	void * d2 = calloc(size, sizeof(int));
// 	printf("%s\n",(char *)d1);
// 	printf("%s\n",(char *)d2);
// 	if (memcmp(d1, d2, size * sizeof(int)))
// 		printf("unquo");
// 	free(d1);
// 	free(d2);
// }
