/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:33:17 by marai             #+#    #+#             */
/*   Updated: 2023/03/30 04:46:34 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_line	t_line;
struct					s_line
{
	char				value;
	int					is_checked;
};

typedef struct s_map	t_map;
struct					s_map
{
	char				*line;
	t_map				*prev;
	t_map				*next;
};

typedef struct s_image	t_image;
struct					s_image
{
	void				*img;
	char				*relative_path;
	int					img_width;
	int					img_height;
};

typedef struct s_vars	t_vars;
struct					s_vars
{
	void				*mlx;
	void				*win;
	t_line				**line;
	ssize_t				map_width;
	ssize_t				map_height;
	ssize_t				pre_x;
	ssize_t				pre_y;
	ssize_t				player_x;
	ssize_t				player_y;
};
#endif
