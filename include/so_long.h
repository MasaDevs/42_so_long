#ifndef SO_LONG_H
#define SO_LONG_H
#define	EDGE	1
#define MIDDLE	0
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "struct.h"
//map.c
t_map	*open_map(char	*map_name);
void	is_rectangle(t_map *map);
//err.c
void	err_so_long(char *str);
void	check_args(t_map *map);
#endif
