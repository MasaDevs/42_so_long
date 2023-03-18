/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:28:21 by marai             #+#    #+#             */
/*   Updated: 2022/10/11 10:56:47 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
