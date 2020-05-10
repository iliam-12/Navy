/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int	my_getnbr(char *str)
{
    int	i;
    int nbr;

    i = 0;
    nbr = 0;
    if (str[i] < '0' && str[i] > '9')
        i = i + 1;
    else {
        while (str[i] >= '0' && str[i] <= '9') {
            nbr = ((nbr * 10) + (str[i] - 48));
            i = i + 1;
        }
    }
    return (nbr);
}

char *my_strcat(char *dest, char *src)
{
    int count;
    int i;

    count = 0;
    i = 0;
    if (dest != NULL && src != NULL) {
        while (dest[count] != '\0')
            count += 1;
        while (src[i] != '\0')
            dest[count++] = src[i++];
        dest[count] = '\0';
        return (dest);
    }
    return (dest);
}

void my_put_nbr(int n)
{
    int c;

    c = 0;
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        my_put_nbr(n / 10);
    c = ((n % 10) + '0');
    write(1, &c, 1);
}