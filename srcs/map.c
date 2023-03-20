#include "get_next_line.h"
#include "so_long.h"

static t_map	*init_map(t_map *pre_map, char *map_line);
static void		init_line(t_map *map, char *map_line);
static void	make_map(int fd, t_map	*map);

t_map	*open_map(char *map_name)
{
	int		fd;
	t_map	*map_head;

	fd = open(map_name, O_RDONLY);
	map_head = init_map(NULL, NULL);
	make_map(fd, map_head);
	return (map_head);
}

static void	make_map(int fd, t_map	*map)
{
	char	*map_line;

	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line || !*map_line)
			break ;
		map = init_map(map, map_line);
		if (!map)
			err_so_long("map error\n");
	}
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
	map->next = NULL;
	init_line(map, map_line);
	return (map);
}
//malloc
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
