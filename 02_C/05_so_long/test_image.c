#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *mlx;
    void *mlx_win;
    void *img;
    char *relative_path = "./game_images/enemy_bonus.xpm";
    int img_width;
    int img_height;
    int win_width = 800;
    int win_height = 500;

    /* initialize connectino & new win */
    mlx = mlx_init();
    if (!mlx)
        return (1);
    mlx_win = mlx_new_window(mlx, win_width, win_height, "image display");
    if (!mlx_win)
    {
        //mlx_destroy_display(mlx);
        free(mlx);
        return (1);
    }

    /* import & convert xpm to image */
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    if (!img)
    {
        mlx_destroy_window(mlx, mlx_win);
        //mlx_destroy_display(mlx);
        free(mlx);
        return (1);
    }
    
    /* cal how many times to tile the image to fill the whole windown 
        then put the image to the win */
    int x_times = (win_width + img_width - 1) / img_width;
    int y_times = (win_height + img_height - 1)/ img_height;

    for (int y = 0; y < y_times; y++)
    {
        for (int x = 0; x < x_times; x++)
        {
            mlx_put_image_to_window(mlx, mlx_win, img, x * img_width, y * img_height);        
        }
    }
    mlx_loop(mlx);

    /* clean up */
    mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, mlx_win);
    //mlx_destroy_display(mlx);
    return (0);
}