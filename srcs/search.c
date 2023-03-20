#include "so_long.h"

t_map	*search_start(t_map *map)
{
	ssize_t	i;

	if (!map)
		err_so_long("map doesn't exist");
	map = map->next;
	while (map && map->next)
	{
		i = 0;
		while (map->line && map->line[i].value)
		{
			if (map->line[i].value == 'P')
				return (map);
			i++;
		}
		map = map->next;
	}
	err_so_long("start point doesn't exist");
}

void	search_col(t_map *map, ssize_t position)
{
	char	ch;

	ch = map->line[position].value;
	if (ch == '1' || ch == 'E' || ch == '\0' ||
		map->line[position].is_checked == 1)
		return ;
	if(0 < position)
		
	if(map->prev->line)

	if(map->next)
}