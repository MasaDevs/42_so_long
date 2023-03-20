#include "so_long.h"
void	check_inside(t_map *map, int c, ssize_t num);
void	check_up_btm(t_map *map);

void	err_so_long(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	is_rectangle(t_map *map)
{
	ssize_t	map_len;
	ssize_t	len;

	if (!map || !map->next || !map->next->line)
		err_so_long("map doesn't exist");
	map = map->next;
	map_len = 0;
	while(map->line && map->line[map_len].value)
		map_len++;
	while (map)
	{
		len = 0;
		while(map->line && map->line[len].value)
			len++;
		if(map_len != len)
			err_so_long("this map is not rectangle");
		map = map->next;
	}
}

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
