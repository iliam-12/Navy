/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** legit_check
*/

#include "my.h"

int check_coord(char **tab, int x, int y)
{
    while (tab[y]) {
        x++;
        if (tab[y][x] == '\0') {
            x = 0;
            y++;
        }
        if (x > 6)
            return (84);
    }
    if (y != 4)
        return (84);
    if (check_letter_coord(tab) == 84)
        return (84);
    if (check_on(tab) == 84)
        return (84);
    return (0);
}

int letter(char **tab, int y, int x)
{
    if (tab[y][x] == 'A')
        return (2);
    if (tab[y][x] == 'B')
        return (4);
    if (tab[y][x] == 'C')
        return (6);
    if (tab[y][x] == 'D')
        return (8);
    if (tab[y][x] == 'E')
        return (10);
    if (tab[y][x] == 'F')
        return (12);
    if (tab[y][x] == 'G')
        return (14);
    if (tab[y][x] == 'H')
        return (16);
    return (0);
}

char **corresp(char **map, char **tab, int x, int y)
{
    int v = 3;
    int k, u, w, right;
    while (y != 4) {
        w = tab[y][v] - 46;
        k = tab[y][0];
        u = k;
        right = 32;
        if (tab[y][2] == tab[y][5]) {
            while (k != 48) {
                map[w][letter(tab, y, x) - 32] = u;
                w += 1;
                k--;
            }
            y++;
        }
        else {
            while (k != 48) {
                map[w][letter(tab, y, x) - right] = u;
                right -= 2;
                k--;
            }
            y++;
        }
    }
    return (map);
}

char **my_tab2(void)
{
    char **tab = malloc(sizeof(char) * 50);

    tab[0] = "2:C4:D4";
    tab[1] = "3:H1:H3";
    tab[2] = "4:E6:H6";
    tab[3] = "5:B1:F1";

    return (tab);
}