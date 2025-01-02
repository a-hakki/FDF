#include "fdf.h"

char    **ft_read(int fd, char *filename)
{
    char    **file;
    char    *line;
    int     line_counter;
    int     i;

    i = 0;
    line_counter = 0;
    line = get_next_line(fd);
    while (line)
    {
        free(line);
        line_counter++;
        line = get_next_line(fd);
    }
    file = (char **)malloc((line_counter + 1) * sizeof(char *));
    if (!file)
        return (NULL);
    fd = open(filename, O_RDONLY);
    while (i < line_counter + 1)
        file[i++] = get_next_line(fd);
    return (file);
}

void draw_line_segment(void *mlx, void *win, t_vec coord)
{
    float   t;
    int     i = 0;
    float x, y;
    int steps = 200; // Number of points to compute for the line

    while (i <= steps)
    {
        t = (float)i / steps; // Vary t from 0 to 1
        x = coord.X0 + t * (coord.X1 - coord.X0);
        y = coord.Y0 + t * (coord.Y1 - coord.Y0);
        mlx_pixel_put(mlx, win, (int)round(x), (int)round(y), 0x00fff0);
        i++;
    }
}


void draw_line(int **tab, int lines, int columns)
{
    t_vec   coord;
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1000 , 1000, "3D Isometric Projection");

    if (!mlx || !win)
        return ;
    int scale = 20;
    int height_scale = 2;
    float x_offset = 500 - (columns * scale * cos(M_PI / 4)) / 2;
    float y_offset = 500 - (lines * scale * sin(M_PI / 4)) / 2;

    int j = 0;
    while (j < lines) {
        int i = 0;
        while (i < columns) {
            int X0 = x_offset + (i * scale - j * scale) * cos(M_PI / 4);
            int Y0 = y_offset + (i * scale + j * scale) * sin(M_PI / 4) - (tab[j][i] * height_scale);

            if (i + 1 < columns)
            {
                int X1 = x_offset + ((i + 1) * scale - j * scale) * cos(M_PI / 4);
                int Y1 = y_offset + ((i + 1) * scale + j * scale) * sin(M_PI / 4) - (tab[j][i + 1] * height_scale);
                coord.X0 = X0;
                coord.Y0 = Y0;
                coord.X1 = X1;
                coord.Y1 = Y1;
                draw_line_segment(mlx, win, coord);
            }
            if (j + 1 < lines)
            {
                int X1 = x_offset + (i * scale - (j + 1) * scale) * cos(M_PI / 4);
                int Y1 = y_offset + (i * scale + (j + 1) * scale) * sin(M_PI / 4) - (tab[j + 1][i] * height_scale);
                coord.X0 = X0;
                coord.Y0 = Y0;
                coord.X1 = X1;
                coord.Y1 = Y1;
                draw_line_segment(mlx, win, coord);
            }
            i++;
        }
        j++;
    }
    mlx_loop(mlx);
}

void free_file(char **file, int line_counter)
{
    for (int i = 0; i < line_counter; i++)
    {
        free(file[i]);
    }
    free(file);
}

void    feed_tab(char **file, int lines, int **tab)
{
    int i = 0;
    tab = (int **)malloc(lines * sizeof(int *));
    char ***splited_file = (char ***)malloc((lines + 1) * sizeof(char **));
    if(!tab)
        return (perror("Allocation failed"));
    while (file[i])
    {
        splited_file[i] = ft_split(ft_strtrim(file[i], "\n "), ' ');
        i++;
    }
    splited_file[i] = NULL;
    i = 0;
    int j = 0;
    while (splited_file[i] != NULL)
    {
        j = 0;
        while (splited_file[i][j])
            j++;
        tab[i] = (int *)malloc(j * sizeof(int *));
        if(!tab[i])
            return (perror("Allocation failed"));
        j = 0;
        while (splited_file[i][j])
        {
            tab[i][j] = ft_atoi(splited_file[i][j]);
            j++;
        }
        i++;
    }
    draw_line(tab, i, j);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    int i = 0;
    int **tab;
    char    **file;

    if (fd == -1)
    {
        perror("Failed to open file");
        return (1);
    }
    file = ft_read(fd, av[1]);
    if (!file)
    {
        close(fd);
        perror("Failed to read file");
        return (1);
    }
    while (file[i])
        i++;
    feed_tab(file, i, tab);
    free_file(file, i);
    close(fd);
    return (0);
}