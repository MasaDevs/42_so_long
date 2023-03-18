/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:50:16 by marai             #+#    #+#             */
/*   Updated: 2022/10/10 23:19:42 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[len - i] == (char)c)
			return ((char *)&(s[len - i]));
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
int	main(void)
{
	char	*s;

	s = "libft-test-tokyo";
	
	printf("%s\n",strrchr(s, 'l' + 256));
	printf("%s\n",ft_strrchr(s, 'l' + 256));
	printf("%s\n",strrchr(s, 'i' + 256));
	printf("%s\n",ft_strrchr(s, 'i' + 256));
}
*/