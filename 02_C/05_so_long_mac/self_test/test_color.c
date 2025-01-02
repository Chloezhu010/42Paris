#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
    return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
    return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
    return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
    return (trgb & 0xFF);
}

int add_shade(double distance, int color)
{
    int t = get_t(color);
    int r = get_r(color);
    int g = get_g(color);
    int b = get_b(color);

    /* restrict distance between 0 and 1 
        0: no shades; 1: complete dark */
    if (distance < 0)
        distance = 0;
    if (distance > 1)
        distance = 1;
    
    /* cal new RGB values with shading */
    r = (int)(r * (1 - distance));
    g = (int)(g * (1 - distance));
    b = (int)(b * (1 - distance));

    return create_trgb(t, r, g, b);
}

int main()
{
    int color = create_trgb(255, 255, 165, 0);
    printf("original color values:\n");
    printf("T: %d, R: %d, G: %d, B: %d\n", 
        get_t(color), get_r(color), get_g(color), get_b(color));
    
    double shades[] = {0, 0.25, 0.5, 0.75, 1.0};
    for (int i = 0; i < 5; i++)
    {
        int shaded = add_shade(shades[i], color);
        printf("new color values:\n");
        printf("T: %d, R: %d, G: %d, B: %d\n\n", 
        get_t(shaded), get_r(shaded), get_g(shaded), get_b(shaded));
    }
    return (0);
}