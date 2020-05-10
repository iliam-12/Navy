/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_str_is_alpha_num
*/

#include "../include/my.h"

int char_isalpha(char c, char d)
{
    if (c < 65 || c > 72)
        return (84);
    if (d < 65 || d > 72)
        return (84);
    return (0);
}

int char_isnum(char c, char d)
{
    if (c < 49 || c > 56)
        return (84);
    if (d < 49 || d > 56)
        return (84);
    return (0);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}