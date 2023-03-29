/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:33:55 by marai             #+#    #+#             */
/*   Updated: 2023/03/30 04:04:15 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <string.h>

static t_map	*make_map(int fd);
static t_map	*init_map(t_map *pre_map, char *map_line);

t_map	*open_map(char *map_name)
{
	int		fd;
	t_map	*map_head;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		err_so_long("can't open the map");
	map_head = make_map(fd);
	close(fd);
	return (map_head);
}

static t_map	*make_map(int fd)
{
	t_map	*map_head;
	t_map	*map;
	char	*map_line;
	char	*new_line;

	map_head = init_map(NULL, NULL);
	map = map_head;
	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			break ;
		new_line = ft_strchr(map_line, '\n');
		if (new_line)
			*new_line = '\0';
		map = init_map(map, map_line);
		if (!map)
		{
			close(fd);
			map_free(map_head);
			err_so_long("map malloc error\n");
		}
	}
	return (map_head);
}
//malloc
static t_map	*init_map(t_map *pre_map, char *map_line)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return NULL;
	if (pre_map == NULL)
		map->prev = NULL;
	else
	{
		map->prev = pre_map;
		map->prev->next = map;
	}
	map->line = map_line;
	map->next = NULL;
	return (map);
}

ssize_t	linelcpy(t_line *dst, char *src, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i + 1 < len && src[i] != '\0')
	{
		if (src[i] == '\n')
			break ;
		dst[i].value = src[i];
		dst[i].is_checked = 0;
		i++;
	}
	if (len != 0)
		dst[i].value = '\0';
	dst[i].is_checked = 0;
	return (ft_strlen(src));
}

t_line	**make_args(t_map *map)
{
	t_line	**line_args;
	ssize_t	args_len;
	ssize_t	i;

	args_len = check_shapes(map);
	line_args = malloc(sizeof(t_line *) * (args_len + 1));
	if (!line_args)
		err_so_long("malloc error");
	map = map->next;
	i = 0;
	while (i < args_len)
	{
		line_args[i] = malloc(sizeof(t_line) * ft_strlen(map->line) + 1);
		if (!line_args[i])
			line_free(line_args, i);
		linelcpy(line_args[i], map->line, ft_strlen(map->line) + 1);
		map = map->next;
		i++;
	}
	line_args[i] = NULL;
	map_free(map);
	return (line_args);
}
