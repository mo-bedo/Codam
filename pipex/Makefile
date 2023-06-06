# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 16:46:43 by jbedaux           #+#    #+#              #
#    Updated: 2022/01/25 16:46:49 by jbedaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Files
FILES_SRCS = 	main.c \
 				parse_file.c \
 				error.c \
       			parse_argv.c

FILES_OBJS = $(FILES_SRCS:.c=.o)

LIBFT = ./srcs/libftprintf/libft.a

NAME = pipex

# Directories
DIR_SRCS = srcs/

DIR_OBJS = objs/

DIR_LIBFT = srcs/libftprintf/

vpath %.c $(DIR_SRCS)

# Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# Create files
all : $(LIBFT) $(DIR_OBJS) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

$(DIR_OBJS)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories
$(DIR_OBJS) :
	@mkdir -p $@

# Create Libft
$(LIBFT) :
	make -C $(DIR_LIBFT)

# Cleaning
clean :
	make clean -C $(DIR_LIBFT)
	rm -rf $(DIR_OBJS)

fclean : clean
	make fclean -C $(DIR_LIBFT)
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all
