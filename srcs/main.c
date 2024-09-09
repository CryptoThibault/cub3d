#include "cub3d.h"

int	main(int ac, char **av)
{
	t_input	*input;
	if (ac != 2)
		return (printf("Usage: %s <infile>", av[0]), 1);
	input = get_input(av[1]);
	return (EXIT_SUCCESS);
}
