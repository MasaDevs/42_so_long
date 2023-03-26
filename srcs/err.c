#include "so_long.h"
#include <string.h>

void	check_paras(t_line **line, char chr, const ssize_t count);

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
		if(len == 0)
			flags = 1;
		if ((map_len != len && flags == 0) || (len != 0 && flags == 1))
			err_so_long("this map is not rectangle");
		map = map->next;
	}
}

void	check_compose(t_line **line)
{
	ssize_t x;
	ssize_t y;
	char	chr;

	y = 0;
	while (line && line[y])
	{
		x = 0;
		while (line[y][x].value)
		{
			chr = line[y][x].value;
			if (chr != '0' && chr != '1' && chr != 'E' && chr != 'C' && chr != 'P')
				err_so_long("maps must be made by 0, 1, E, P, C");
			x++;
		}
		y++;
	}
	printf("ok\n");
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
		err_so_long("invalid map\n");
}
/*
void	check_args(t_map *map)
{
	if (!map)
		err_so_long("map doesn't exist");
	check_up_btm(map->next);
	check_inside(map->next->next, 'C', -1);
	check_inside(map->next->next, 'P', 1);
	check_inside(map->next->next, 'E', 1);
}

void	check_up_btm(t_map *map)
{
	ssize_t	i;

	i = 0;
	while(map->line && map->line[i].value)
	{
		if(map->line[i].value != '1')
			err_so_long("invalid map");
		i++;
	}
	while(map && map->next)
		map = map->next;	
	i = 0;
	while(map->line && map->line[i].value)
	{
		if(map->line[i].value != '1')
			err_so_long("invalid map");
		i++;
	}
}

void	check_inside(t_map *map, int c, ssize_t num)
{
	ssize_t	i;
	ssize_t	count;
	char	ch;

	count = 0;
	while(map && map->next)
	{
		i = 0;
		if(map->line[i].value != '1')
			err_so_long("invalid map");
		while (map->line && map->line[i].value)
		{
			ch = map->line[i].value;
			if(ch != '1' && ch != '0' && ch != 'C' && ch != 'P' && ch != 'E')
				err_so_long("invalid map");
			if(ch == c)
				count++;	
			i++;
		}
		if(i <= 0 || map->line[i - 1].value != '1')
			err_so_long("invalid map");
		map = map->next;	
	}
	if((num > 0 && count != num) || (num < 0 && count <= 0))
		err_so_long("invalid map");
}
*/
