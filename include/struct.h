#ifndef STRUCT_H
#define	STRUCT_H

typedef	struct s_line	t_line;
struct s_line
{
	char	value;
	int		is_checked;
};

typedef struct s_map	t_map;
struct	s_map
{
	t_line		*line;
	t_map		*prev;
	t_map		*next;
};
#endif