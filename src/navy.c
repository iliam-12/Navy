/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "my.h"

int check_attack(char *str)
{
    if (str == NULL)
        return (42);
    if (my_strlen(str) != 2)
        return (84);
    if (str[0] != 'A' && str[0] != 'B' && str[0] != 'C' && str[0] != 'D'
        && str[0] != 'E' && str[0] != 'F' && str[0] != 'G' && str[0] != 'H')
        return (84);
    if (str[1] < '0' || str[1] > '9')
        return (84);
    return (0);
}

pid_t setup(void)
{
    pid_t pid;

    pid = getpid();
    write(1, "my_pid: ", 8);
    my_put_nbr(pid);
    write(1, "\n", 1);
    return (pid);
}

int first_player(char **tab, char **tab2)
{
    int my_pid;
    int his_pid;
    int command;

    my_pid = setup();
    my_pid = my_pid;
    write(1, "waiting for enemy connection...\n", 32);
    his_pid = pid_handler();
    print_map_1(tab);
    while (check_attack != 0) {
        write(1, "attack: ", 8);
        command = check_attack(get_next_line(0));
        if (command == 42)
            return (42);
        if (command == 84)
            write(1, "wrong position\n", 16);
    }
}

int second_player(char **av, char **tab, char **tab2)
{
    int my_pid;
    int his_pid;
    int command;

    my_pid = setup();
    his_pid = my_getnbr(av[1]);
    pidsender(my_pid, his_pid);
    signal(SIGUSR2, sighandler);
    pause();
    print_map_1(tab2);
    while (check_attack != 0) {
        write(1, "attack: ", 8);
        command = check_attack(get_next_line(0));
        if (command == 42)
            return (42);
        if (command == 84)
            write(1, "wrong position\n", 16);
    }
}

int navy(int ac, char **av, int fd)
{
    char *buff, *buff2;
    int size_map;
    char **tab, **tab2 = my_tab2();
    struct stat fileStat;

    if (fd == -1)
        return (84);
    if (ac == 2) {
        if (stat(av[1], &fileStat) == -1)
            return (84);
        size_map = fileStat.st_size;
        buff = malloc(sizeof(char) * (size_map + 26));
        read(fd, buff, size_map);
        tab = my_str_to_word_array(buff);
        if (check_coord(tab, 0, 0) == 84)
            return (84);
        if (first_player(tab, tab2) == 42)
            return (42);
    }
    if (ac == 3) {
        if (stat(av[2], &fileStat) == -1)
            return (84);
        buff2 = malloc(sizeof(char) * (size_map + 26));
        read(fd, buff2, size_map);
        tab2 = my_str_to_word_array(buff2);
        if (check_coord(tab2, 0, 0) == 84)
            return (84);
        second_player(av, tab, tab2);
    }
    return (0);
}