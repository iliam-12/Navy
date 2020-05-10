/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "my.h"

int *dectobin(int nb)
{
    int save = nb;
    int *tab;
    int i = 0;

    while ((save / 10) != 0) {
        save = save / 10;
        i += 1;
    }
    tab = malloc(sizeof(int) * (17));
    tab[16] = 2;
    while (i != 16)
        tab[i++] = 2;
    save = nb;
    i = 0;
    while (i != 16) {
        tab[i] = save % 2;
        save = save / 2;
        i += 1;
    }
    return (tab);
}

int pid_handler(void)
{
    int pid2;

    signal(SIGUSR1, sighandler);
    pause();
    pid2 = sig_getnb();
    usleep(2000);
    kill(pid2, SIGUSR2);
    return (pid2);
}

int pidsender(int my_pid, int his_pid)
{
    int *tab;

    kill(his_pid, SIGUSR1);
    tab = dectobin(my_pid);
    sender(his_pid, tab);
    signal(SIGUSR2, sighandler);
    free(tab);
    return (0);
}