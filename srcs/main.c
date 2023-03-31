/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:36 by marai             #+#    #+#             */
/*   Updated: 2023/03/31 10:47:08 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_size(t_vars *vars);

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_map	*map;

	if (argc != 2)
		err_so_long("arguments must be 2.");
	check_file_name(argv[1]);
	map = open_map(argv[1]);
	is_rectangle(map);
	is_sorrounded(map);
	vars.line = make_args(map);
	search_start(&vars);
	check_compose(vars.line);
	search(vars.line, vars.player_y, vars.player_x);
	check_map(vars.line);
	calc_size(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_width * SIZE, vars.map_height
			* SIZE, "so_long");
	drawing(&vars);
	mlx_hook(vars.win, 2, 1L << 0, update_map, &vars);
	mlx_expose_hook(vars.win, drawing, &vars);
	mlx_hook(vars.win, 17, 1L << 2, escape, &vars);
	mlx_loop(vars.mlx);
	line_free(vars.line, vars.map_height);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q so_long");
}
