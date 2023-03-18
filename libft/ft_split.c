/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:09:18 by marai             #+#    #+#             */
/*   Updated: 2022/10/17 13:18:32 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numofsplit(char const *s, char c)
{
	long long	pre;
	long long	now;
	size_t		counter;

	now = 0;
	pre = -2;
	counter = 0;
	while (s[now] != '\0')
	{
		if (s[now] != c)
		{
			if (now > 1 + pre)
				counter++;
			pre = now;
		}
		now++;
	}
	return (counter);
}

static int	mallofree(char **dst, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (1);
}

static char	*makesentense(char **dst, char *front, char c, size_t i)
{
	char	*end;

	while (*front == c && *front != '\0')
		front++;
	end = front;
	while (*end != c && *front != '\0' && *end != '\0')
		end++;
	dst[i] = malloc(sizeof(char) * (end - front + 1));
	if (dst[i] == NULL && mallofree(dst, i))
		return (NULL);
	ft_strlcpy(dst[i], front, end - front + 1);
	front = end;
	i++;
	return (front);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*front;
	char	**dst;

	if (!s)
		return (NULL);
	i = 0;
	dst = malloc(sizeof(char *) * (ft_numofsplit(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	front = (char *)s;
	while (i < ft_numofsplit(s, c))
	{
		front = makesentense(dst, front, c, i);
		if (front == NULL)
			return (NULL);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

/*
char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*front;
	char	*end;
	char	**dst;

	if (!s)
		return (NULL);
	i = 0;
	dst = malloc(sizeof(char *) * (ft_numofsplit(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	front = (char *)s;
	while (i < (ft_numofsplit(s, c)))
	{
		while (*front == c && *front != '\0')
			front++;
		end = front;
		while (*end != c && *front != '\0' && *end != '\0')
			end++;
		dst[i] = malloc(sizeof(char) * (end - front + 1));
		if (dst[i] == NULL && mallofree(dst, i))
			return (NULL);
		ft_strlcpy(dst[i], front, end - front + 1);
		front = end;
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
*/

// int main()
// {
// 	char str[] = "My name is Masahito";
// 	test(str);
// 	printf("%s\n", str);
// 	char *splitme = ft_strdup("--1-2--3---4----5-----42");
// 	char **tab = ft_split(splitme, '-');
// 	int i = 0;
// 	printf("%zu\n",ft_numofsplit(splitme, '-'));
// 	while (1)
// 	{
// 		printf("%s\n", tab[i]);
// 		if (!tab[i])
// 			break ;
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	char	arr[] = "awassaupaaa";
// 	char	**tmp;
// 	printf("%zu\n", ft_numofsplit(arr, 'a'));
// 	tmp = ft_split(arr,'a');
// 	printf("%s\n", tmp[1]);
// }
