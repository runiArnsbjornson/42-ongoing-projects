# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 15:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/06/23 09:37:28 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_DIR = srcs/

FILE = main.c parser.c solver.c display.c utils.c check.c

SRC = $(addprefix $(SRC_DIR), $(FILE)) 

OBJ = $(SRC:.c=.o)

HEAD = includes/lem_in.h

INCL = -I includes -I libft/includes -I libft/Libft

LIBS = -Llibft -lftprintf

CFLAGS = -Wall -Wextra -Weverything -Werror -fdiagnostics-show-option -pedantic

all: $(NAME)

%.o: %.c $(HEAD)
	@gcc -g -o $@ -c $< $(CFLAGS) $(INCL)
	@echo "\033[K\033[34mCompiling\033[00m : \033[32m$<\033[00m"

$(NAME): $(OBJ)
	@cd libft && make
	@gcc $(LIBS) -g -o $(NAME) $(OBJ) $(INCL)
	@echo "\033[K\033[32m$(NAME)\033[00m : \033[34mCreated\033[00m"

clean:
	@cd libft && make clean
	@rm -f $(OBJ)
	@echo "\033[31mClean\033[01m Done\033[00m"

fclean: clean
	@rm -f libft/libftprintf.a libft/libft/libft.a $(NAME)
	@echo "\033[31mFclean\033[01m Done\033[00m"

mclean: all clean
	@echo "\033[K\033[33mMake && clean \033[01mDone\033[0m"

re: fclean
	@make
	@echo "\033[32mRe\033[01m Done\033[0m"

.PHONY: all clean fclean mclean re
