#include "so_long.h"

void	error(char *err_mess)
{
	write(2, "Error\n", 6);
	ft_printf("%s", err_mess);
	exit(EXIT_FAILURE);
}
