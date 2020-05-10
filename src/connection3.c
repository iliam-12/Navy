/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "my.h"

void sighandler(int sig)
{
    if (sig == SIGUSR1) {
        signal(sig, SIG_IGN);
        write(1, "\nenemy connected\n\n", 18);
    }
    if (sig == SIGUSR2) {
        signal(sig, SIG_IGN);
        write(1, "successfully connected\n\n", 24);
    }
}

void hdlusr(int sig)
{
    if (sig == SIGUSR1) {
        g_ch = 1;
        signal(sig, SIG_IGN);
    }
    if (sig == SIGUSR2) {
        g_ch = 0;
        signal(sig, SIG_IGN);
    }
}

int sig_getnb(void)
{
    int nb = 0;
    int tab[16];
    int i = 0;

    while (i != 16) {
        signal(SIGUSR1, hdlusr);
        signal(SIGUSR2, hdlusr);
        pause();
        if ((g_ch != 1) || (g_ch != 0))
            tab[i++] = g_ch;
    }
    nb = getnbfrombin(tab);
    return (nb);
}