#include "so_long.h"

static int  count_coll_left(char **map);
static t_point  *alloc_play(t_total *total);

t_point *find_player(t_total *tot)
{
    t_point *player;
    int x;
    int y;

    player = alloc_play(tot);
    y = 0;
    while (tot->map[y])
    {
        x = 0;
        while (tot->map[y][x])
        {
            if (tot->map[y][x] == 'P')
            {
                player->x = x;
                player->y = y;
                return (player);
            }
            x++;
        }
        y++;
    }
    player->x = -1;
    player->y = -1;
    return (player);
}

static t_point  *alloc_play(t_total *total)
{
    t_point *play;

    play = (t_point *) malloc(sizeof(t_point));
    if (!play)
        err_screen("Malloc error\n", total);
    return (play);
}

int check_avail_exit(t_total *tot)
{
    int coll_left;

    coll_left = count_coll_left(tot->map);
    if (coll_left != 0)
    {
        ft_printf("Can't leave game: %i bottles collected, %i bottles left.\n",
            g_collect, coll_left);
        return (0);
    }
    if (coll_left == 0)
    {
        ft_printf("Congrats! You collected %i bottles and left the game.\n",
            g_collect);
        succ_exit("", tot);
    }
    return (1);
}

static int  count_coll_left(char **map)
{
    int x;
    int y;
    int coll_left;

    coll_left = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C')
                coll_left++;
            x++;
        }
        y++;
    }
    return (coll_left);
}