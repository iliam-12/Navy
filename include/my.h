/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

/* ___ INCLUDES ___ */

#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

# ifndef MY_H_
#  define MY_H_

typedef struct Var_s {
    char **map;
}Var_t;

/* ___ FONCTIONS ___ */

char **my_tab2(void);
char **enemy_map(char **map);
char **corresp(char **map, char **tab, int x, int y);
int check_coord(char **tab, int x, int y);
int letter(char **tab, int y, int x);
char **my_str_to_word_array(char const *str);
int nb_char(char const *str, int i);
int nb_line(char const *str);
void print_oui(char **map, char **tab);
char *get_next_line(const int fd);
void print_map_1(char **);
int g_ch;
int kill(pid_t pid, int sig);
int my_strlen(char *);
void my_putchar(char);
void my_putstr(char *);
int my_getnbr(char *);
void my_put_nbr(int);
char *my_strcat(char *, char *);
char *my_realloc(char *, int);
int navy(int, char **, const int);
int first_player(char **, char **);
int second_player(char **, char **, char **);
void sighandler(int);
int sig_getnb();
int sender(int, int *);
pid_t setup();
int getnbfrombin(int *);
int *dectobin(int);
int pidsender(int, int);
int powa(int, int);
int pid_handler();
int char_isalpha(char c, char d);
int char_isnum(char c, char d);
int check_length(char *str);
int check_letter_coord(char **tab);
char **put_map(void);
int put_col(int size, int col, Var_t *var, int start);
int put_line(int size, int line, Var_t *var, int start);
int put_boat(char **cor, Var_t *var);
int check_on(char **tab);

#endif /* !MY_H_ */

