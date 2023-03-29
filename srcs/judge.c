#include "so_long.h"

void	check_goal(t_vars *vars, ssize_t x, ssize_t y)
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
			{
				ft_printf("you don't collect all items !\n");
				return ;
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
	line_free(vars->line, vars->map_height);
	exit(0);
}

void	change_locale(t_vars *vars, ssize_t x, ssize_t y)
{
	static size_t	count;

	if (move_or_not(vars, x, y))
	{
		count++;
		ft_printf("%ld\n", count);
		vars->line[vars->player_y][vars->player_x].value = '0';
		vars->line[vars->player_y + y][vars->player_x + x].value = 'P';
		vars->pre_x	= vars->player_x;
		vars->pre_y = vars->player_y;
		vars->player_x = vars->player_x + x;
		vars->player_y = vars->player_y + y;
	}
}

int	move_or_not(t_vars *vars, ssize_t x, ssize_t y)
{
	if (x && vars->player_x && vars->line[vars->player_y][vars->player_x
		+ x].value)
	{
		if (vars->line[vars->player_y][vars->player_x + x].value == 'C'
			|| vars->line[vars->player_y][vars->player_x + x].value == '0')
			return (1);
		else if (vars->line[vars->player_y][vars->player_x + x].value == 'E')
			check_goal(vars, x, y);
	}
	else if (y && vars->player_y && vars->line[vars->player_y])
	{
		if (vars->line[vars->player_y + y][vars->player_x].value == 'C'
			|| vars->line[vars->player_y + y][vars->player_x].value == '0')
			return (1);
		else if (vars->line[vars->player_y + y][vars->player_x].value == 'E')
			check_goal(vars, x, y);
	}
	return (0);
}
