# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 19:57:24 by mfadil            #+#    #+#              #
#    Updated: 2023/01/01 17:23:40 by mfadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SERVER = server.o

CLIANT = client.o

B_SERVER = server_bonus.o

B_CLIANT = client_bonus.o

SRV = server

CLT = client

BSRV = server_bonus

BCLT = client_bonus

all: pr $(SRV) $(CLT)

bonus: pr $(BSRV) $(BCLT)

pr:
	@cd printf && make

$(SRV): $(SERVER) minitalk.h
	$(CC) $(CFLAGS) $(SERVER) ./printf/libftprintf.a -o $(SRV)

$(CLT): $(CLIANT) minitalk.h
	$(CC) $(CFLAGS) $(CLIANT) ./printf/libftprintf.a -o $(CLT)

$(BSRV): $(B_SERVER) minitalk.h
	$(CC) $(CFLAGS) $(B_SERVER) ./printf/libftprintf.a -o $(BSRV)

$(BCLT): $(B_CLIANT) minitalk.h
	$(CC) $(CFLAGS) $(B_CLIANT) ./printf/libftprintf.a -o $(BCLT)

clean:
	rm -rf $(SERVER) $(CLIANT)
	rm -rf $(B_SERVER) $(B_CLIANT)
	cd printf && make clean

fclean: clean
	rm -rf $(SRV) $(CLT)
	rm -rf $(BSRV) $(BCLT)
	cd printf && make fclean

re: fclean all

.PHONY: all bonus clean fclean re