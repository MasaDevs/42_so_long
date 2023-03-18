/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:54:47 by marai             #+#    #+#             */
/*   Updated: 2022/12/10 15:07:48 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = i;
		while (haystack[j] == needle[j - i] && j < len && haystack[j] != '\0')
			j++;
		if (haystack[j - 1] == needle[j - i - 1] && needle[j - i] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	//printf("%s", strnstr(NULL, "is",100));
	//printf("%s", strnstr("masahito", "ss",100));
	//printf("%s", ft_strnstr("masahito", "ss",15));
	//printf("%s", strnstr(NULL, NULL,5));
	//printf("%s", ft_strnstr(NULL, NULL,5));
	// printf("%s", ft_strnstr(NULL, NULL,5));
	//printf("%s", strnstr("masahito", NULL,0));
	//printf("%s", ft_strnstr("masato", NULL,0));
}
*/

// if (len == 0 || ft_strlen(needle) > len)
// 	return (NULL);
