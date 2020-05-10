/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** error_file
*/

#include "../include/my.h"

int check_length(char *str)
{
    if (str[2] == str[5]) {
        if (((str[6] + 24) - (str[3] + 24)) != (str[0] - 1))
            return (84);
    }
    if (str[3] == str[6]) {
        if (((str[5] + 24) - (str[2] + 24)) != (str[0] - 1))
            return (84);
    }
    return (0);
}

int check_letter_coord(char **tab)
{
    if (tab[0][0] != '2' || tab[1][0] != '3')
        return (84);
    if (tab[2][0] != '4' || tab[3][0] != '5')
        return (84);
    for (int y = 0; y != 4; y++) {
        if (tab[y][1] != ':' || tab[y][4] != ':')
            return (84);
        if (char_isalpha(tab[y][2], tab[y][5]) == 84)
            return (84);
        if (char_isnum(tab[y][3], tab[y][6]) == 84)
            return (84);
        if (tab[y][2] != tab[y][5] && tab[y][3] != tab[y][6])
            return (84);
        if (tab[y][2] > tab[y][5] || tab[y][3] > tab[y][6])
            return (84);
        if (check_length(tab[y]) == 84)
            return (84);
    }
    return (0);
}