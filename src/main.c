/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "my.h"

void print_h(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n     first_player_pid:  only for the 2nd player.");
    my_putstr("  pid of the first player.\n");
    my_putstr("navy_positions:  file representing");
    my_putstr(" the positions of the ships.\n");
}

int main(int ac, char **av)
{
    int err;
    int fd;
    int error;

    ac == 3 ? fd = open(av[2], O_RDONLY) : 0;
    ac == 2 ? fd = open(av[1], O_RDONLY) : 0;
    if (ac != 2 && ac != 3) {
        my_putstr("Error with arguments\n");
        return (84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_h();
        return (0);
    }
    error = navy(ac, av, fd);
    if (error == 84)
        return (84);
    if (error == 42)
        return (0);
    return (0);
}