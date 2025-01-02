#include "fdf.h"
// --------execute command----------
// gcc x.c libmlx.a libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libftprintf.a libgetnextline.a -g

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
void draw_line(int **tab, int lines, int columns)
{
    void *mlx_connection = mlx_init();
    void *mlx_window = mlx_new_window(mlx_connection, 1000, 1000, "3D Isometric Projection");
    int i = 0;
    int j = 0;
    float scale = 15;
    float height_scale = 5;

    float max_width = columns * scale * cos(M_PI / 6);
    float max_height = lines * scale * sin(M_PI / 6);

    int x_offset = 500 - (max_width / 2);
    int y_offset = 500 - (max_height / 2);
    while (j < lines)
    {
        i = 0;
        while (i < columns)
        {
            int X0 = x_offset + (i * scale - j * scale) * cos(M_PI / 6);
            int Y0 = y_offset + (i * scale + j * scale) * sin(M_PI / 6) - (tab[j][i] * height_scale);
            if (i + 1 < columns)
            {
                int X1 = x_offset + ((i + 1) * scale - j * scale) * cos(M_PI / 6);
                int Y1 = y_offset + ((i + 1) * scale + j * scale) * sin(M_PI / 6) - (tab[j][i + 1] * height_scale);
                int dx = abs(X1 - X0);
                int dy = abs(Y1 - Y0);
                int sx = (X0 < X1) ? 1 : -1;
                int sy = (Y0 < Y1) ? 1 : -1;
                int err = dx - dy;

                while (1)
                {
                    mlx_pixel_put(mlx_connection, mlx_window, X0, Y0, 0xffffff);
                    if (X0 == X1 && Y0 == Y1)
                        break;
                    int e2 = 2 * err;
                    if (e2 > -dy)
                    {
                        err -= dy;
                        X0 += sx;
                    }
                    if (e2 < dx)
                    {
                        err += dx;
                        Y0 += sy;
                    }
                }
            }
            if (j + 1 < lines)
            {
                int X1 = x_offset + (i * scale - (j + 1) * scale) * cos(M_PI / 6);
                int Y1 = y_offset + (i * scale + (j + 1) * scale) * sin(M_PI / 6) - (tab[j + 1][i] * height_scale);
                int dx = abs(X1 - X0);
                int dy = abs(Y1 - Y0);
                int sx = (X0 < X1) ? 1 : -1;
                int sy = (Y0 < Y1) ? 1 : -1;
                int err = dx - dy;

                while (1)
                {
                    mlx_pixel_put(mlx_connection, mlx_window, X0, Y0, 0xffffff);
                    if (X0 == X1 && Y0 == Y1)
                        break;
                    int e2 = 2 * err;
                    if (e2 > -dy)
                    {
                        err -= dy;
                        X0 += sx;
                    }
                    if (e2 < dx)
                    {
                        err += dx;
                        Y0 += sy;
                    }
                }
            }
            i++;
        }
        j++;
    }
    mlx_loop(mlx_connection);
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