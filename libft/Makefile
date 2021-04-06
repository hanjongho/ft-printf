# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 16:48:45 by hanjongho         #+#    #+#              #
#    Updated: 2021/01/20 16:49:41 by hanjongho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJECTS = *.o
CFLAGS = -Wall -Wextra -Werror

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	ft_isprint.c ft_memset.c ft_tolower.c ft_toupper.c ft_atoi.c\
	ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
	ft_strchr.c ft_strlen.c ft_strrchr.c ft_calloc.c ft_strdup.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c\
	ft_strtrim.c ft_substr.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strmapi.c ft_strsubjoin.c\
	ft_count_begin_char.c ft_strsub.c ft_strdel.c ft_strnew.c ft_atos.c\
	ft_itoa_base_unsigned.c ft_itoa_unsigned.c ft_strcmp.c ft_int_len.c\

BNSSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

all : $(NAME)

bonus : 
	gcc $(CFLAGS) -c $(SRC) $(BNSSRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME) 

$(NAME) :
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean : 
	/bin/rm -f $(OBJECTS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
