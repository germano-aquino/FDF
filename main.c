#include <fdf.h>
#include <stdio.h>


void my_mlx_put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void chess_board(t_data *img, int step)
{
	int	t;
	int	x;
	int	y;

	for (y = 10; y < HEIGHT; y += step)
	{
		for (x = 0; x < WIDTH; x++)
		{
			my_mlx_put_pixel(img, x, y, BLUE);
			if (x % 10 == 0 && y < HEIGHT)
			{
				for (t = 0; t < step; t++) my_mlx_put_pixel(img, x, t + y, RED);
			}
		}
	}
}

int close(int keycode, t_env *env)
{
	printf("this is keycode: %d\n", keycode);
	if (keycode == 27) mlx_destroy_window(env->mlx, env->win);
	return (0);
}
int main (){

	t_env	env;
	t_data	img;
	int		step = 10;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "FDF");
	img.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	img.bits_per_pixel = 32;
	img.line_length = WIDTH;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	chess_board(&img, step);
	mlx_put_image_to_window(env.mlx, env.win, img.img, 0, 0);
	mlx_key_hook(env.win, close, &env);
	mlx_loop(env.mlx);
	return (0);
}