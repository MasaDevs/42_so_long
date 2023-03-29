/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:33:44 by marai             #+#    #+#             */
/*   Updated: 2023/03/30 02:30:14 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	check_paras(t_line **line, char chr, const ssize_t count);

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

void	err_so_long(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	is_rectangle(t_map *map)
{
	ssize_t	map_len;
	ssize_t	len;
	ssize_t	flags;

	if (!map || !map->next || !map->next->line)
		err_so_long("map doesn't exist");
	map = map->next;
	map_len = strlen(map->line);
	flags = 0;
	while (map)
	{
		len = strlen(map->line);
		if (len == 0)
			flags = 1;
		if ((map_len != len && flags == 0) || (len != 0 && flags == 1))
			err_so_long("this map is not rectangle");
		map = map->next;
	}
}

void	is_sorrounded(t_map *map)
{
	ssize_t	i;

	if (!map || !map->next || !map->next->line)
		err_so_long("map doesn't exist");
	map = map->next;
	i = 0;
	while (map->line && map->line[i])
	{
		if (map->line[i] != '1')
			err_so_long("1 map is not sorrounded by 1");
		i++;
	}
	map = map->next;
	while (map && map->next)
	{
		if(!map->line || !strlen(map->line))
			break;
		if (!map->line || map->line[0] != '1' || map->line[strlen(map->line)
			- 1] != '1')
			err_so_long("2 map is not sorrounded by 1");
		map = map->next;
	}
	i = 0;
	while (map && map->line && map->line[i])
	{
		if (map->line[i] != '1')
			err_so_long("3 map is not sorrounded by 1");
		i++;
	}
}

void	check_compose(t_line **line)
{
	ssize_t	x;
	ssize_t	y;
	char	chr;

	y = 0;
	while (line && line[y])
	{
		x = 0;
		while (line[y][x].value)
		{
			chr = line[y][x].value;
			if (chr != '0' && chr != '1' && chr != 'E' && chr != 'C'
				&& chr != 'P')
				err_so_long("maps must be made by 0, 1, E, P, C");
			x++;
		}
		y++;
	}
	check_paras(line, 'E', 1);
	check_paras(line, 'P', 1);
	check_paras(line, 'C', 0);
}
void	check_paras(t_line **line, char chr, const ssize_t count)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	nums;

	nums = 0;
	y = 0;
	while (line && line[y])
	{
		x = 0;
		while (line[y][x].value)
		{
			if (chr == line[y][x].value)
				nums++;
			x++;
		}
		y++;
	}
	if ((0 < count && nums != count) || (count == 0 && nums <= 0))
		err_so_long("1 invalid map\n");
}

void	check_file_name(char *str)
{
	while (str)
	{
		str = ft_strnstr(str, ".ber", strlen(str));
		if (!str)
			break ;
		if (strlen(str) == 4)
			return ;
		str++;
	}
	err_so_long("file extension must be '.ber'");
}

int	escape(int keycode)
{
	(void)keycode;
	exit(0);
}