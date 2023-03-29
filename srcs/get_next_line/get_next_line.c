/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:19:34 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 01:21:02 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1ul];
	char		*ans;
	ssize_t		num;

	ans = malloc(sizeof(char) * 1);
	if (!ans)
		return (NULL);
	ans = nullcheck(fd, ans, save);
	if (ans == NULL)
		return (NULL);
	while (1)
	{
		if (ft_strchr(ans, '\n'))
			break ;
		num = read(fd, save, BUFFER_SIZE);
		if (num == -1)
			return (set_free(&ans));
		save[num] = '\0';
		if (num == 0)
			break ;
		ans = ft_strjoinfree(ans, save);
		if (!ans)
			return (NULL);
	}
	return (returnvalue(ans, save));
}

char	*nullcheck(char fd, char *ans, char *save)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(ans);
		return (NULL);
	}
	*ans = 0;
	ans = ft_strjoinfree(ans, save);
	return (ans);
}

char	*returnvalue(char *ans, char *save)
{
	char	*ptr;

	ptr = ft_strchr(ans, '\n');
	if (ans && ptr)
		ft_memmove(save, ptr + 1, ft_strlen(ptr));
	else if (*ans == '\0')
		return (set_free(&ans));
	else
		return (ans);
	return (ft_strndupfree(ans, ptr - ans + 1));
}

char	*set_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	char	*str;
	int		fd;

	fd = open("a.txt", O_RDONLY);
	printf("%d\n", fd);
	while(1)
	{
		str = get_next_line(0);
		printf("%s\n", str);
		if(!str)
			break;
		free(str);
	}
}
*/
