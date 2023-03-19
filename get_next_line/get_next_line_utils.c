/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:14:40 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 01:21:23 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndupfree(char *s1, size_t n)
{
	char	*dst;
	size_t	i;

	if (!s1)
		return (NULL);
	dst = malloc(sizeof(char) * (n + 1));
	if (dst == NULL)
		return (set_free(&s1));
	i = 0;
	while (i < n)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	set_free(&s1);
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t	a;

	if (!str)
		return (0);
	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char			*dst;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (set_free(&s1));
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	set_free(&s1);
	return (dst);
}

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	if (buf1 == NULL || buf2 == NULL)
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
