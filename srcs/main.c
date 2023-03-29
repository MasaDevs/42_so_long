/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:36 by marai             #+#    #+#             */
/*   Updated: 2023/03/29 22:18:29 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	check_C(vars.line);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, MAP_WIDTH, MAP_HEIGHT, "so_long");
	drawing(&vars);
	mlx_hook(vars.win, 2, 1L << 0, update_map, &vars);
	mlx_hook(vars.win, 17, 1L << 2, escape, NULL);
	mlx_loop(vars.mlx);
}

//__attribute__((destructor)) static void destructor()
//{
//	system("leaks -q so_long");
//}
