#include "so_long.h"

int main(int argc, char **argv)
{
    char    **map;

    if (argc != 2)
        return (ft_printf("Enter the map naming\n"), 1);
    if (!ft_strnstr(*(argv + 1), ".ber", ft_strlen(*(argv + 1))))
        return (ft_printf("Incorrect map extension (only .ber is allowed)\n"), 1);
    map = map_init(*(argv + 1));
    if (!map)
        return (1);
    free(map);
    return (0);
}