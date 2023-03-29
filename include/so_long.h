/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:33:08 by marai             #+#    #+#             */
/*   Updated: 2023/03/30 05:26:21 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
/* for linux
# define ESC 65307
# define D_ALLOW 65363
# define W_ALLOW 65362
# define A_ALLOW 65361
# define S_ALLOW 65364
# define S_KEY 115
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
*/
# define ESC 53
# define D_ALLOW 124
# define W_ALLOW 126
# define A_ALLOW 123
# define S_ALLOW 125
# define S_KEY 1
# define W_KEY 13
# define A_KEY 0
# define D_KEY 2
# define EDGE 1
# define MIDDLE 0
# define SIZE 64

//map.c
t_map	*open_map(char *map_name);
ssize_t	check_shapes(t_map *map);
t_line	**make_args(t_map *map);
//search.c
void	search_start(t_vars *vars);
void	search(t_line **line, ssize_t x, ssize_t y);
void	check_map(t_line **line);
//draw
int		update_map(int keycode, t_vars *vars);
void	drawing(t_vars *vars);
//err.c
void	err_so_long(char *str);
void	is_rectangle(t_map *map);
void	check_compose(t_line **line);
void	is_sorrounded(t_map *map);
int		escape(t_vars *vars);
//free
void	map_free(t_map *map);
void	line_free(t_line **line, ssize_t len);
void	line_free_exit(t_line **line, char *str);
//check
void	check_file_name(char *str);
//judge
void	change_locale(t_vars *vars, ssize_t x, ssize_t y);
int		move_or_not(t_vars *vars, ssize_t x, ssize_t y);
void	check_goal(t_vars *vars, ssize_t x, ssize_t y);

#endif
