#include "fdf.h"

int is_valid(const char c)
{
    char *str = "0123456789abcdef";
    int i = 0;
    while (str[i])
    {
        if (c == str[i])
            return (i);
        i++;
    }
    return (-1);
}

int ft_color(const char *s)
{
    int i;
    i = 0;
    int d;
    d = 0;
    if (!s)
        return (0);
    while (s[i] != ',')
        i++;
    i++;
    if (s[i++] == '0')
    {
        if (s[i++] == 'x')
        {
            while (s[i] && is_valid(s[i]) != -1)
                d = (d * 16) + is_valid(s[i++]);
            return (d);
            
        }
    }
    else
    return (0);
}
// int main()
// {
//     int d = ft_color("rgrd,0xffffff\n");
//     printf("%x\n", d);
//     printf("%d\n", d);
// }