# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 16:46:43 by jbedaux           #+#    #+#              #
#    Updated: 2022/02/16 12:43:28 by jbedaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
CC = gcc

CFLAGS = -Wall -Werror -Wextra -pthread -g

# Files
FILES_SRCS =    time_utils.c \
				create_threads_mutexes.c \
                main.c \
				parse_and_set.c \
                utils.c \
                start_simulation.c \
                print.c \
                monitoring.c \
                usleep.c \
                parse_argv.c \
                eat_sleep_think.c

FILES_OBJS = $(FILES_SRCS:.c=.o)

NAME = philo

# Sources
SRCS = $(FILES_SRCS)

# Objects
OBJS = $(FILES_OBJS)

# Create files
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

re_sanit : fclean sanit

.PHONY : re fclean clean all re_sanit
