/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "my.h"

void print_map_1(char **tab)
{
    int x = 0;
    int y = 0;
    int number = 49;
    int letter = 65;
    char **map = malloc(sizeof(char *) * 10);

    for (int i = 0; i != 11; i++) {
        if ((map[i] = malloc(sizeof(char) * 18)) == NULL)
            map[i][17] = '\0';
    }
    while (y < 10) {
        while (x < 17) {
            if (x != 2)
                map[y][x] = '|';
            if (x != 1)
                map[y][x] = ' ';
            if (y == 1)
                map[y][x] = '-';
            map[1][1] = '+';
            if (x > 1 && y > 1) {
                map[y][x] = '.';
                x++;
                map[y][x] = ' ';
            }
            if (y > 1 && x == 0) {
                map[y][x] = number;
                number++;
            }
            if (x > 1 && y == 0) {
                map[y][x] = letter;
                x++;
                map[y][x] = ' ';
                letter++;
            }
            x++;
        }
        x = 0;
        y++;
    }
    print_oui(map, tab);
}

char **enemy_map(char **map)
{
    map[0] = " |A B C D E F G H";
    map[1] = "-+---------------";
    map[2] = "1|. . . . . . . . ";
    map[3] = "2|. . . . . . . . ";
    map[4] = "3|. . . . . . . . ";
    map[5] = "4|. . . . . . . . ";
    map[6] = "5|. . . . . . . . ";
    map[7] = "6|. . . . . . . . ";
    map[8] = "7|. . . . . . . . ";
    map[9] = "8|. . . . . . . . ";
    return (map);
}

void print_oui(char **map, char **tab)
{
    int i = 0;

    my_putstr("my positions:\n");
    while (i != 10) {
        corresp(map, tab, 2, 0);
        my_putstr(map[i]);
        my_putstr("\n");
        i++;
    }
    my_putstr("\n");
    my_putstr("enemy's positions:\n");
    i = 0;
    while (i != 10) {
        enemy_map(map);
        my_putstr(map[i]);
        my_putstr("\n");
        i++;
    }
    my_putstr("\n");
}