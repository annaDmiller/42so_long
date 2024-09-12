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
# include "../mlx_linux/mlx.h"
# define HEIGHT 750
# define LENGTH 1300
# define ESC 65307

typedef struct	s_win {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_total {
	t_img  *img;
	t_win  *mlx;
	char	***map;
}				t_total;

char    **map_init(char *map_addr);
char    *str_realloc(char *src, size_t size);
void    error(char  *err_mess);
int    validate_cep(char *map_line);
void    validate_letters(char *map_line);
void    validate_map_arr(char **map, int quan_c);
void validate_border(char **map);
void    validate_collect(char **map, int quan_c);
char **create_temp_map(char **map);
void    screen_logic(char **map);
int button_logic(int keycode, t_total *total);
int button_cross_logic(t_total *total);
#endif