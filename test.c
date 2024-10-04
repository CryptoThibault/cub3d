#include "mlx/mlx.h"

int	main(void) 
{
	void	*mlx_ptr = mlx_init();
	int	win_x;
	int	win_y;
	mlx_get_screen_size(mlx_ptr, &win_x, &win_y);
	void	*win_ptr = mlx_new_window(mlx_ptr, win_x / 2, win_y, "Test");
	int	tex_x;
	int	tex_y;
	void	*texture = mlx_xpm_file_to_image(mlx_ptr, "textures/N-letter.xpm", &tex_x, &tex_y);

	int bpp;
	int size_line;
	int endian;
	char *data = mlx_get_data_addr(texture, &bpp, &size_line, &endian);

	int y = 0;
	while (y < win_y)
	{
		int x = 0;
		while (x < win_x / 2)
		{
			int tex_x_scaled = (x * tex_x) / (win_x / 2);
			int tex_y_scaled = (y * tex_y) / win_y;
			int pixel_pos = tex_y_scaled * size_line + tex_x_scaled * (bpp / 8);
			int color = *(int *)(data + pixel_pos);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}

	mlx_loop(mlx_ptr);
	return (0);
}
