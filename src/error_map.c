/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** error_map
*/

#include "../include/my.h"

char **put_map(void)
{
    char **tab = malloc(sizeof(char *) * 8);
    int y = 0, x = 0;

    for (int i = 0; i != 8; i++)
        tab[i] = malloc(sizeof(char) * 10);
    while (y != 8) {
        while (x != 8) {
            tab[y][x] = '.';
            x++;
        }
        tab[y][8] = '\n';
        tab[y][9] = '\0';
        x = 0;
        y++;
    }
    return (tab);
}

int put_col(int size, int col, Var_t *var, int start)
{
    int i = 0;

    while (i != size) {
        if (var->map[start][col] == 'O')
            return (84);
        var->map[start][col] = 'O';
        start++;
        i++;
    }
    return (0);
}

int put_line(int size, int line, Var_t *var, int start)
{
    int i = 0;

    while (i != size) {
        if (var->map[line][start] == 'O')
            return (84);
        var->map[line][start] = 'O';
        start++;
        i++;
    }
}

int put_boat(char **cor, Var_t *var)
{
    int y = 0, line = 0, col = 0, error = 0;

    while (cor[y]) {
        if (cor[y][2] == cor[y][5]) {
            col = cor[y][2] - 65;
            error = put_col(cor[y][0] - 48, col, var, cor[y][3] - 49);
        }
        if (cor[y][3] == cor[y][6]) {
            line = cor[y][3] - 49;
            error = put_line(cor[y][0] - 48, line, var, cor[y][2] - 65);
        }
        if (error == 84)
            return (84);
        y++;
    }
}

int check_on(char **tab)
{
    Var_t *var = malloc(sizeof(Var_t));

    var->map = put_map();
    if (put_boat(tab, var) == 84) {
        free(var);
        return (84);
    }
    return (0);
}