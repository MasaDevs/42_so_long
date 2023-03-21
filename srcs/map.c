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
	map_head = make_map(fd);
	close(fd);
	return (map_head);
}

static t_map	*make_map(int fd)
{
	t_map	*map_head;
	t_map	*map;
	char	*map_line;

	map_head = init_map(NULL, NULL);
	map = map_head;
	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			break ;
		map = init_map(map, map_line);
		if (!map)
			err_so_long("map error\n");
	}
	return (map_head);
}
//malloc
static t_map	*init_map(t_map *pre_map, char *map_line)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		err_so_long("map malloc error");
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


ssize_t	check_shapes(t_map *map)
{
	char	*str;
	ssize_t	count;
	int		flags;

	if(!map)
		err_so_long("map doesn't exist");
	map = map->next;
	count = 0;
	flags = 0;
	while(map)
	{
		if(!strcmp(map->line, "\n"))
			flags = 1;
		else
			count++;
		if(strcmp(map->line, "\n") && flags == 1)
			err_so_long("map error");
		str = strchr(map->line, '\n');
		if(str)
			*str = '\0';
		map = map->next;
	}
	return (count);
}

ssize_t	linelcpy(t_line *dst, char	*src, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i + 1 < len)
	{
		dst[i].value = src[i];
		dst[i].is_checked = 0;
		i++;
	}
	dst[i].value = '\0';
	dst[i].is_checked = 0;
	
	return (len);
}

t_line	**make_args(t_map *map)
{
	t_line	**line_args;
	ssize_t	args_len;
	ssize_t	i;

	args_len = check_shapes(map);
	line_args = malloc(sizeof(t_line *) * (args_len + 1));
	if(!line_args)
		err_so_long("malloc error");
	i = 0;
	map = map->next;
	while (i < args_len)
	{
		line_args[i] = malloc(sizeof(t_line) * strlen(map->line) + 1);
		if(!line_args[i])
			err_so_long("malloc error");
		linelcpy(line_args[i], map->line, strlen(map->line) + 1);
		map = map->next;
		i++;
	}
	line_args[i] = NULL;
	return (line_args);
}
//malloc
/*
static void	init_line(t_map *map, char *map_line)
{
	ssize_t	i;
	ssize_t	len;
	t_line	*line;

	if (!map_line)
		map->line = NULL;
	else
	{
		len = ft_strlen(map_line);
		line = malloc(sizeof(t_line) * (len + 1));
		if (!line)
			err_so_long("line malloc error");
		i = 0;
		while (i < len)
		{
			if (map_line[i] == '\n')
				line[i].value = '\0';
			else
				line[i].value = map_line[i];
			line[i].is_checked = 0;
			i++;
		}
		map->line = line;
		free(map_line);
	}
}
*/