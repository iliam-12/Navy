##
## EPITECH PROJECT, 2019
## /
## File description:
## /
##

CC	= gcc

SRCS	= main.c		\
	  navy.c		\
	  toolbox.c		\
	  connection3.c		\
	  connection.c		\
	  connection2.c		\
	  get_next_line.c	\
	  legit_check.c     \
	  my_str_is_alpha_num.c \
	  my_str_to_word_array.c    \
	  error_file.c \
	  error_map.c \
	  print_map.c

CFLAGS  += -I./include


HEAD	= my.h		\
	  proto.h	\
	  lib.h		\
	  structure.h	\
	  macrow.h	\

OBJS	= $(addprefix src/, $(SRCS:.c=.o))

NAME	= navy

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
	rm $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
