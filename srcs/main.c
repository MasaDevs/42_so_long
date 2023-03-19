#include "so_long.h"

typedef struct	s_image {
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;


int close(int keycode, t_vars *vars)
{
	if(keycode)
		printf("%d\n", keycode);
	if(keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_image	img;

	vars.mlx = mlx_init();
	vars.win= mlx_new_window(vars.mlx, 1080, 1080, "Hello world!");
	img.img = mlx_xpm_file_to_image(vars.mlx, "./images/nami.xpm", &img.img_width, &img.img_height);
	if(img.img == NULL)
		printf("no image\n");
	printf("%d %d\n", img.img_height, img.img_width);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 110, 110);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}