/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:27:57 by marai             #+#    #+#             */
/*   Updated: 2022/10/11 01:12:32 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

/*
#include <libc.h>
#include <string.h>
int	main(void)
{
	char	*str;
	char	*cmp2;
	int		len;

	str = "libft-test-tokyo";
	cmp2 = calloc(10, 1);
	strlcpy(cmp2, "libft", 10);
	len = strlen(str);
	printf("%s %s\n", str, cmp2);
	cmp2[5] = -45;
	printf("%d\n",  strncmp(str, cmp2, len));
	printf("%d\n",  ft_strncmp(str, cmp2, len));
}
*/

// if(s2[i] < 0)
// 	return (-1 * 211 - s2[i]);