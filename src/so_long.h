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
# define HEIGHT_MAX 750
# define LENGTH_MAX 1320
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 1731
# define D 1751
# define A 1734
# define S 1753

typedef struct s_win
{
	void	*mlx;
	void	*win;
}			t_win;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}			t_img;

typedef struct s_map_img
{
	t_img	*coll;
	t_img	*wall;
	t_img	*floor;
	t_img	*player;
	t_img	*exit;
}			t_map_img;

typedef struct s_total
{
	t_map_img	*img;
	t_win		*mlx;
	char		**map;
}				t_total;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

extern volatile unsigned int	g_steps;
extern volatile unsigned int	g_collect;

char	**map_init(char *map_addr);
char	*str_realloc(char *src, size_t size);
void	error(char *err_mess);
int		validate_cep(char *map_line);
void	validate_letters(char *map_line);
void	validate_map_arr(char **map, int quan_c);
void	validate_border(char **map);
void	validate_collect(char **map, int quan_c);
char	**create_temp_map(char **map);
void	screen_logic(char **map);
int		button_logic(int keycode, t_total *total);
int		button_cross_logic(t_total *total);
void	draw_map(t_total *total);
void	free_map_img(t_map_img *map_img, void *mlx, int check);
void    player_move_up(t_total *tot);
void    player_move_down(t_total *tot);
void    player_move_left(t_total *tot);
void    player_move_right(t_total *tot);
t_point *find_player(t_total *tot);
int check_avail_exit(t_total *tot, t_point *play);
void    err_arr(char *mess, char **map);
void    err_screen(char *mess, t_total *tot, int check);
void    succ_exit(char *mess, t_total *tot);
#endif
