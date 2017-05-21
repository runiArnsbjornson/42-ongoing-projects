# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 13:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/05/19 15:22:02 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCL = -I includes/ -I libft/

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
	srcs/search.c \
	srcs/get.c \
	srcs/func.c \
	srcs/precision.c \
	srcs/printer.c \
	srcs/wprinter.c \
	handlers/bin_handler.c \
	handlers/char_handler.c \
	handlers/dec_handler.c \
	handlers/float_handler.c \
	handlers/hex_handler.c \
	handlers/oct_handler.c \
	handlers/percent_handler.c \
	handlers/string_handler.c \
	handlers/utf8_convert.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(LIBS) -g -o $@ -c $< $(CFLAGS) $(INCL)
	@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME): $(OBJS)
	@cd Libft && make
	@libtool -static -o $@ $^ libft/libft.a
	@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[0m"

clean:
	@cd Libft && make clean
	@/bin/rm -f $(OBJS)
	@echo "\033[31mClean \033[35mDone\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) ./libft/libft.a
	@echo "\033[31mFclean \033[35mDone\033[0m"

re: fclean all
	@echo "\033[K\033[32m*** Re Done ***\033[00m"

.PHONY : all clean fclean re
