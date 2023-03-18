/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:52:16 by marai             #+#    #+#             */
/*   Updated: 2022/12/10 15:07:08 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	else if ((size_t)start >= ft_strlen(s) || len == 0)
	{
		dst[0] = '\0';
		return (dst);
	}
	i = 0;
	while (i < len && s[(size_t)start + i] != '\0')
	{
		dst[i] = s[(size_t)start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
