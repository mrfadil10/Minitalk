# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 19:17:01 by mfadil            #+#    #+#              #
#    Updated: 2022/12/22 21:43:45 by mfadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c\
	  ft_printf_utils.c\
	  ft_printf_utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ)
	ar cr $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean

