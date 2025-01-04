#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}
int	mouse_hook(int keycode, t_vars *vars)
{
	if (keycode == 5)
        vars->x = vars->x + 0.1;
	return (0);
}

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

void draw_line_segment(t_vars *vars, t_vec coord)
{
    float   t;
    int     i = 0;
    float   x, y;
    int steps = 200;

    while (i <= steps)
    {
        t = (float)i / steps;
        x = coord.X0 + t * (coord.X1 - coord.X0);
        y = coord.Y0 + t * (coord.Y1 - coord.Y0);
        if (x >= 0 && x < vars->line_length / 4 && y >= 0 && y < 1000)
        {
            char *dst = vars->addr + ((int)y * vars->line_length + (int)x * (vars->bits_per_pixel / 8));
            *(unsigned int *)dst = coord.c;
        }
        i++;
    }

}

void draw_line(t_vec *var, int lines, int columns)
{
    t_vec   coord;
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
    vars.img = mlx_new_image(vars.mlx, 1000, 1000);
    vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);

    if (!vars.mlx || !vars.win)
        return ;
    float x = 1.7;
    vars.x = x;
    int scalex = 10 * vars.x;
    int scaley = 12 * vars.x;
    int height_scale = 1 * vars.x;
    float x_offset = 350;
    float y_offset = 250;

    int j = 0;
    while (j < lines) {
        int i = 0;
        while (i < columns) {
            int X0 = x_offset + (i * scalex - j * scaley) * cos(M_PI / 5);
            int Y0 = y_offset + (i * scalex + j * scaley) * sin(M_PI / 5) - (var->tab[j][i] * height_scale);
            coord.c = var->color[j][i];
            if (i + 1 < columns)
            {
                int X1 = x_offset + ((i + 1) * scalex - j * scaley) * cos(M_PI / 5);
                int Y1 = y_offset + ((i + 1) * scalex + j * scaley) * sin(M_PI / 5) - (var->tab[j][i + 1] * height_scale);
                coord.X0 = X0;
                coord.Y0 = Y0;
                coord.X1 = X1;
                coord.Y1 = Y1;
                draw_line_segment(&vars, coord);
            }
            if (j + 1 < lines)
            {
                int X1 = x_offset + (i * scalex - (j + 1) * scaley) * cos(M_PI / 5);
                int Y1 = y_offset + (i * scalex + (j + 1) * scaley) * sin(M_PI / 5) - (var->tab[j + 1][i] * height_scale);
                coord.X0 = X0;
                coord.Y0 = Y0;
                coord.X1 = X1;
                coord.Y1 = Y1;
                draw_line_segment(&vars, coord);
            }
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_loop(vars.mlx);
}

void free_file(char **file, int line_counter)
{
    for (int i = 0; i < line_counter; i++)
    {
        free(file[i]);
    }
    free(file);
}

void    feed_tab(char **file, int lines)
{
    int returned_val;
    int i = 0;
    t_vec	vars;
    vars.tab = (int **)malloc(lines * sizeof(int *));
    vars.color = (int **)malloc(lines * sizeof(int *));
    char ***splited_file = (char ***)malloc((lines + 1) * sizeof(char **));
    if(!vars.tab || !vars.color)
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
        vars.tab[i] = (int *)malloc(j * sizeof(int *));
        vars.color[i] = (int *)malloc(j * sizeof(int *));
        if(!vars.tab[i] || !vars.color)
            return (perror("Allocation failed"));
        j = 0;
        while (splited_file[i][j])
        {
            vars.tab[i][j] = ft_atoi(splited_file[i][j]);
            vars.color[i][j] = ft_color(splited_file[i][j]);
            j++;
        }
        i++;
    }
    draw_line(&vars, i, j);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    int i = 0;

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
    feed_tab(file, i);
    free_file(file, i);
    close(fd);
    return (0);
}