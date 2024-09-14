#include "so_long.h"

volatile unsigned int	g_steps;

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (ft_printf("Enter the map naming\n"), 1);
	if (!ft_strnstr(*(argv + 1), ".ber", ft_strlen(*(argv + 1))))
		return (ft_printf("Only .ber maps are allowed)\n"), 1);
	g_steps = 0;
	map = map_init(*(argv + 1));
	if (!map)
		return (1);
	screen_logic(map);
	free(map);
	return (0);
}
