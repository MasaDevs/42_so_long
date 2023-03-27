#include "so_long.h"
/*
int main()
{
	t_map	*map;
	t_line	**line;
	ssize_t	i;
	ssize_t	j;
	map = open_map("a.txt");
	is_rectangle(map);
	line = make_args(map);
	search(line, 2, 3);
	check_C(line);
	map = map->next;
	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j].value)
		{
			printf("%c", line[i][j].value);
			j++;
		}
		printf("\n");
		map = map->next;
		i++;
	}
}
*/


int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_map	*map;

	if(argc != 2)
		err_so_long("arguments must be 2.");
	check_file_name(argv[1]);
	map = open_map(argv[1]);
	is_rectangle(map);
	is_sorrounded(map);
	vars.line = make_args(map);
	search_start(&vars);
	check_compose(vars.line);
	search(vars.line, vars.player_x, vars.player_y);
	check_C(vars.line);
	vars.mlx = mlx_init();
	vars.win= mlx_new_window(vars.mlx, MAP_WIDTH, MAP_HEIGHT, "so_long");
	drawing(&vars);
	mlx_hook(vars.win, 2, 1L<<0, update_map, &vars);
	mlx_loop(vars.mlx);
}
