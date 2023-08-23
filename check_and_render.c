#include "so_long.h"

int check_and_render_up(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
    char **livemap = wdata->imgdata.livemap.live_map;
    if(move_up(direction, cur_x, cur_y, wdata))
    {
        render(wdata, livemap);
        return(1);
    }
    return(0);
}

int check_and_render_down(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
    char **livemap = wdata->imgdata.livemap.live_map;
    if(move_down(direction, cur_x, cur_y, wdata))
    {
        render(wdata, livemap);
        return(1);
    }
    return(0);
}

int check_and_render_left(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
    char **livemap = wdata->imgdata.livemap.live_map;
    if(move_left(direction, cur_x, cur_y, wdata))
    {
        render(wdata, livemap);
        return(1);
    }
    return(0);
}

int check_and_render_right(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
    char **livemap = wdata->imgdata.livemap.live_map;
    if(move_right(direction, cur_x, cur_y, wdata))
    {
        render(wdata, livemap);
        return(1);
    }
    return(0);
}
