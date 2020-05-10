/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "my.h"

int getnbfrombin(int *tab)
{
    int i = 0;
    int j = 0;
    int res = 0;

    while (j != 16) {
        if (tab[i] == 1)
            res = res + powa(2, j);
        i += 1;
        j += 1;
    }
    return (res);
}

int powa(int nb, int pow)
{
    int i = 0;
    int save = nb;

    if (pow == 0)
        return (1);
    if (pow == 1)
        return (nb);
    while ((i + 1) != pow) {
        nb = nb * save;
        i += 1;
    }
    return (nb);
}

int sender(int pid, int *tab)
{
    int i = 0;

    while (tab[i] != 2) {
        usleep(2000);
        if (tab[i] == 1)
            kill(pid, SIGUSR1);
        if (tab[i] == 0)
            kill(pid, SIGUSR2);
        i += 1;
    }
    return (0);
}