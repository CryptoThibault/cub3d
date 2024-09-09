#include "cub3d.h"

char	*get_texture(char *line, char *prefix)
{

}

int	[3]get_rgb(char *line, char *prefix)
{
	
}

char	**get_map(int fd)
{
	char	**map;
	t_pos	pos;

	
	while ()
}

t_input	*get_input(char *infile)
{
	t_input	*input;
	int	fd;
	char	*new_line;

	if (!infile /*check .cub*/)
	{
		printf("Extention .cub required");
		exit(EXIT_FAILURE);
	}

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: can't open infile");
		exit(EXIT_FAILURE);
	}
	input = malloc(sizeof(t_input));
	input->north_texture = get_texture(get_next_line(fd), "NO");
	input->south_texture = get_texture(get_next_line(fd), "SO");
	input->west_texture = get_texture(get_next_line(fd), "WE");
	input->east_texture = get_texture(get_next_line(fd), "EA");
	new_line = get_next_line(fd);
	free(new_line);
	input->floar_rgb = get_rgb(get_next_line(fd), "F");
	input->ceiling_rgb = get_rgb(get_next_line(fd), "C");
	new_line = get_next_line(fd);
	free(new_line);
	input->map = get_map(fd);
}
