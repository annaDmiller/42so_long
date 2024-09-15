#include "so_long.h"

void    player_move_up(t_total *tot)
{
    t_point *play;
    int     check_coll;

    check_coll = -1;
    play = find_player(tot);
    if (play->x == -1)
        err_screen("Unknown error: impossible to find player\n", tot);
    if (tot->map[play->y - 1][play->x] == '1')
        return ;
    if (tot->map[play->y - 1][play->x] == 'C')
        g_collect++;
    g_steps++;
    if (tot->map[play->y - 1][play->x] == 'E')
        check_coll = check_avail_exit(tot);
    if (check_coll == 0)
        return ;
    tot->map[play->y - 1][play->x] = 'P';
    tot->map[play->y][play->x] = '0';
    free(play);
    draw_map(tot);
    return ;
}

void    player_move_down(t_total *tot)
{
    t_point *play;
    int     check_coll;

    check_coll = -1;
    play = find_player(tot);
    if (play->x == -1)
        err_screen("Unknown error: impossible to find player\n", tot);
    if (tot->map[play->y + 1][play->x] == '1')
        return ;
    if (tot->map[play->y + 1][play->x] == 'C')
        g_collect++;
    g_steps++;
    if (tot->map[play->y + 1][play->x] == 'E')
        check_coll = check_avail_exit(tot);
    if (check_coll == 0)
        return ;
    tot->map[play->y + 1][play->x] = 'P';
    tot->map[play->y][play->x] = '0';
    free(play);
    draw_map(tot);
    return ;
}

void    player_move_left(t_total *tot)
{
    t_point *play;
    int     check_coll;

    check_coll = -1;
    play = find_player(tot);
    if (play->x == -1)
        err_screen("Unknown error: impossible to find player\n", tot);
    if (tot->map[play->y][play->x - 1] == '1')
        return ;
    if (tot->map[play->y][play->x - 1] == 'C')
        g_collect++;
    g_steps++;
    if (tot->map[play->y][play->x - 1] == 'E')
        check_coll = check_avail_exit(tot);
    if (check_coll == 0)
        return ;
    tot->map[play->y][play->x - 1] = 'P';
    tot->map[play->y][play->x] = '0';
    free(play);
    draw_map(tot);
    return ;
}

void    player_move_right(t_total *tot)
{
    t_point *play;
    int     check_coll;

    check_coll = -1;
    play = find_player(tot);
    if (play->x == -1)
        err_screen("Unknown error: impossible to find player\n", tot);
    if (tot->map[play->y][play->x + 1] == '1')
        return ;
    if (tot->map[play->y][play->x + 1] == 'C')
        g_collect++;
    g_steps++;
    if (tot->map[play->y][play->x + 1] == 'E')
        check_coll = check_avail_exit(tot);
    if (check_coll == 0)
        return ;
    tot->map[play->y][play->x + 1] = 'P';
    tot->map[play->y][play->x] = '0';
    free(play);
    draw_map(tot);
    return ;
}