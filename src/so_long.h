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
void    validate_cep(char *map_line);
void    validate_map_arr(char **map);
void validate_border(char **map);
void    validate_collect(char **map);
#endif