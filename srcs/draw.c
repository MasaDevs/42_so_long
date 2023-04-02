/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:33:30 by marai             #+#    #+#             */
/*   Updated: 2023/04/02 15:14:10 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(t_vars *vars, ssize_t x, ssize_t y, t_image img);
void	swap_draw(t_vars *vars);

int	update_map(int keycode, t_vars *vars)
{
	if (keycode == W_KEY || keycode == W_ALLOW)
		change_locale(vars, 0, -1);
	else if (keycode == D_KEY || keycode == D_ALLOW)
		change_locale(vars, 1, 0);
	else if (keycode == A_KEY || keycode == A_ALLOW)
		change_locale(vars, -1, 0);
	else if (keycode == S_KEY || keycode == S_ALLOW)
		change_locale(vars, 0, 1);
	else if (keycode == ESC)
	{
		image_free(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	swap_draw(vars);
	return (0);
}

int	drawing(t_vars *vars)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (vars->line[i])
	{
		j = 0;
		while (vars->line[i][j].value)
		{
			if (vars->line[i][j].value == 'C')
				draw_pixel(vars, j, i, vars->img_blue);
			else if (vars->line[i][j].value == 'P')
				draw_pixel(vars, j, i, vars->img_yellow);
			else if (vars->line[i][j].value == 'E')
				draw_pixel(vars, j, i, vars->img_pink);
			else if (vars->line[i][j].value == '0')
				draw_pixel(vars, j, i, vars->img_green);
			else if (vars->line[i][j].value == '1')
				draw_pixel(vars, j, i, vars->img_red);
			j++;
		}
		i++;
	}
	return (1);
}

void	draw_pixel(t_vars *vars, ssize_t x, ssize_t y, t_image img)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, x * SIZE, y * SIZE);
}

void	swap_draw(t_vars *vars)
{
	draw_pixel(vars, vars->pre_x, vars->pre_y, vars->img_green);
	draw_pixel(vars, vars->player_x, vars->player_y,
		vars->img_yellow);
}


void	img_init(t_vars *vars)
{
	vars->img_red.img = mlx_xpm_file_to_image(vars->mlx, "./images/square-red-64.xpm", &vars->img_red.img_width, &vars->img_red.img_height);
	if (!vars->img_red.img)
		line_free_exit(vars->line, "cannot load images");
	vars->img_green.img = mlx_xpm_file_to_image(vars->mlx, "./images/square-green-64.xpm", &vars->img_green.img_width, &vars->img_green.img_height);
	if (!vars->img_green.img)
		line_free_exit(vars->line, "cannot load images");
	vars->img_yellow.img = mlx_xpm_file_to_image(vars->mlx, "./images/square-yellow-64.xpm", &vars->img_yellow.img_width, &vars->img_yellow.img_height);
	if (!vars->img_yellow.img)
		line_free_exit(vars->line, "cannot load images");
	vars->img_blue.img = mlx_xpm_file_to_image(vars->mlx, "./images/square-blue-64.xpm", &vars->img_blue.img_width, &vars->img_blue.img_height);
	if (!vars->img_blue.img)
		line_free_exit(vars->line, "cannot load images");
	vars->img_pink.img = mlx_xpm_file_to_image(vars->mlx, "./images/square-pink-64.xpm", &vars->img_pink.img_width, &vars->img_pink.img_height);
	if (!vars->img_pink.img)
		line_free_exit(vars->line, "cannot load images");
}

void	image_free(t_vars *vars)
{
	if(vars->img_red.img)
		mlx_destroy_image(vars->mlx, vars->img_red.img);
	if(vars->img_green.img)
		mlx_destroy_image(vars->mlx, vars->img_green.img);
	if(vars->img_yellow.img)
		mlx_destroy_image(vars->mlx, vars->img_yellow.img);
	if(vars->img_blue.img)
		mlx_destroy_image(vars->mlx, vars->img_blue.img);
	if(vars->img_pink.img)
		mlx_destroy_image(vars->mlx, vars->img_pink.img);
}

/*
void	drawing(t_vars *vars)
{
	ssize_t	i;
	ssize_t	j;

	if (MAP_HEIGHT / SIZE < vars->player_y)
		i = vars->player_y - MAP_HEIGHT / SIZE;
	else
		i = 0;
	while (vars->line[i])
	{
		if (MAP_WIDTH / SIZE < vars->player_x)
			j = vars->player_x - MAP_WIDTH / SIZE;
		else
			j = 0;
		while (vars->line[i][j].value)
		{
			if (vars->line[i][j].value == 'C')
				draw_pixel(vars, j, i, "./images/square-blue-64.xpm");
			else if (vars->line[i][j].value == 'P')
				draw_pixel(vars, j, i, "./images/square-yellow-64.xpm");
			else if (vars->line[i][j].value == 'E')
				draw_pixel(vars, j, i, "./images/square-pink-64.xpm");
			else if (vars->line[i][j].value == '0')
				draw_pixel(vars, j, i, "./images/square-green-64.xpm");
			else if (vars->line[i][j].value == '1')
				draw_pixel(vars, j, i, "./images/square-red-64.xpm");
			j++;
		}
		i++;
	}
	fill_space(vars, i, j);
}

void	fill_space(t_vars *vars, ssize_t y, ssize_t x)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (i < y)
	{
		j = x;
		while (j - vars->player_x < MAP_WIDTH / SIZE)
		{
			draw_pixel(vars, j, i, "./images/square-black-64.xpm");
			j++;
		}
		i++;
	}
	while (y - vars->player_y < MAP_HEIGHT / SIZE)
	{
		j = 0;
		while (j - vars->player_x < MAP_WIDTH / SIZE)
		{
			draw_pixel(vars, j, y, "./images/square-black-64.xpm");
			j++;
		}
		y++;
	}
}

void	draw_pixel(t_vars *vars, ssize_t x, ssize_t y, char *path)
{
	t_image	img;

	if (MAP_WIDTH / (SIZE * 2) < vars->player_x)
		x = x - vars->player_x + (MAP_WIDTH / (SIZE * 2));
	if (MAP_HEIGHT / (SIZE * 2) < vars->player_y)
		y = y - vars->player_y + (MAP_HEIGHT / (SIZE * 2));
	img.img = mlx_xpm_file_to_image(vars->mlx, path, &img.img_width,
			&img.img_height);
	if (!img.img)
		err_so_long("image doesn't exist");
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, x * SIZE, y * SIZE);
}
*/
