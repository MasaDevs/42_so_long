/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:36 by marai             #+#    #+#             */
/*   Updated: 2023/03/30 02:33:07 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void calc_size(t_vars *vars);

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
	calc_size(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_width * SIZE, vars.map_height * SIZE, "so_long");
	drawing(&vars);
	mlx_hook(vars.win, 2, 1L << 0, update_map, &vars);
	mlx_hook(vars.win, 17, 1L << 2, escape, NULL);
	mlx_loop(vars.mlx);
}


void calc_size(t_vars *vars)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if(!vars->line)
		err_so_long("map error\n");
	while (vars->line && vars->line[0][i].value)
		i++;
	while (vars->line && vars->line[j])
		j++;
	vars->map_width = i;
	vars->map_height = j;
	
}
//__attribute__((destructor)) static void destructor()
//{
//	system("leaks -q so_long");
//}
