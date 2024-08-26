#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "stdlib.h"
# include "fcntl.h"
# include "math.h"
# include "unistd.h"
# include "stdio.h"
# include "string.h"

char    **map_init(char *map_addr);
char    *str_realloc(char *src, size_t size);
void    error(char  *err_mess);
#endif