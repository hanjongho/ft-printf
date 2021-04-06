# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 23:44:49 by hanjongho         #+#    #+#              #
#    Updated: 2021/01/20 16:55:48 by hanjongho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJECTS = *.o
CFLAGS =  -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
CC = gcc

SRC = ./ft_printf.c \
		./ft_printf_fmt_exception.c \
		./ft_printf_parse.c \
		./ft_printf_parse_fmt.c \
		./ft_printf_set_spec_val.c \

.SILENT:

all: $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS):
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
