# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakahmed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 19:15:07 by hakahmed          #+#    #+#              #
#    Updated: 2023/03/13 03:59:12 by hakahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

LIB = ar -rcs

RM = rm -f

NAME = libftprintf.a

SRC = ft_printf.c ft_functions.c ft_functions2.c

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h 

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS)  -c -o $@ $<  
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
