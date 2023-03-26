#include "so_long.h"
void	draw_pixel(t_vars *vars, ssize_t x, ssize_t y, char *path);
void	change_locale(t_vars *vars, ssize_t x, ssize_t y);
int move_or_not(t_vars *vars, ssize_t x, ssize_t y);
void fill_space(t_vars *vars, ssize_t y, ssize_t x);

int	update_map(int keycode, t_vars	*vars)
{
	if (keycode == 'w')
		change_locale(vars, 0, -1);
	else if (keycode == 'd')
		change_locale(vars, 1, 0);
	else if (keycode == 'a')
		change_locale(vars, -1, 0);
	else if(keycode == 's')
		change_locale(vars, 0, 1);
	else if(keycode == 65307 || keycode == 'x')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	drawing(vars);
	return (0);
}

void check_goal(t_vars *vars, ssize_t x, ssize_t y)
{
	ssize_t i;
	ssize_t	j;

	i = 0;
	while(vars->line[i])
	{
		j = 0;
		while(vars->line[i][j].value)
		{
			if(vars->line[i][j].value == 'C')
			{
				printf("you lose !\n");
				mlx_destroy_window(vars->mlx, vars->win);
				exit(0);
				
			}
			j++;
		}
		i++;
	}
	vars->line[vars->player_y][vars->player_x].value = '0';
	vars->line[vars->player_y + y][vars->player_x + x].value = 'P';
	vars->player_x = vars->player_x + x;
	vars->player_y = vars->player_y + y;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	change_locale(t_vars *vars, ssize_t x, ssize_t y)
{
	static size_t	count;

	if (move_or_not(vars, x, y))
	{
		count++;
		printf("%ld\n", count);
		vars->line[vars->player_y][vars->player_x].value = '0';
		vars->line[vars->player_y + y][vars->player_x + x].value = 'P';
		vars->player_x = vars->player_x + x;
		vars->player_y = vars->player_y + y;
	}

}
int move_or_not(t_vars *vars, ssize_t x, ssize_t y)
{
	if(x && vars->player_x && vars->line[vars->player_y][vars->player_x + x].value)
	{
		if(vars->line[vars->player_y][vars->player_x + x].value == 'C' || vars->line[vars->player_y][vars->player_x + x].value == '0')
			return (1);
		else if(vars->line[vars->player_y][vars->player_x + x].value == 'E')
			check_goal(vars, x, y);
	}
	else if (y && vars->player_y && vars->line[vars->player_y])
	{
		if(vars->line[vars->player_y + y][vars->player_x].value == 'C' || vars->line[vars->player_y + y][vars->player_x].value == '0')
			return (1);
		else if(vars->line[vars->player_y + y][vars->player_x].value == 'E')
			check_goal(vars, x, y);
	}
	return (0);
}

void	drawing(t_vars *vars)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (vars->line[i])
	{
		j = 0;
		while (vars->line[i][j].value)
		{
			if(vars->line[i][j].value == 'C')
				draw_pixel(vars, j, i, "./images/square-blue-64.xpm");
			else if(vars->line[i][j].value == 'P')
				draw_pixel(vars, j, i, "./images/square-yellow-64.xpm");
			else if(vars->line[i][j].value == 'E')
				draw_pixel(vars, j, i, "./images/square-pink-64.xpm");
			else if(vars->line[i][j].value == '0')
				draw_pixel(vars, j, i, "./images/square-green-64.xpm");
			else if(vars->line[i][j].value == '1')
				draw_pixel(vars, j, i, "./images/square-red-64.xpm");
			j++;
		}
		i++;
	}
	fill_space(vars, i, j);
}

void fill_space(t_vars *vars, ssize_t y, ssize_t x)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (i < y)
	{
		j = x;
		while(j - vars->player_x < MAP_WIDTH / SIZE)
		{
			draw_pixel(vars, j, i, "./images/square-black-64.xpm");
			j++;
		}
		i++;
	}
	while(y - vars->player_y < MAP_HEIGHT / SIZE)
	{
		j = 0;
		while(j < MAP_WIDTH / SIZE)
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
	if(!img.img)
		err_so_long("image doesn't exist");
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, x * SIZE, y * SIZE);
}