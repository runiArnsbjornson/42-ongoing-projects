# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 15:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/05/03 10:59:03 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jdebladi.filler

INCL = -I Libft/libft -I includes

LIBS = -Llibft -lftprintf

CFLAGS =

SRC = srcs/filler.c srcs/search.c srcs/display.c srcs/main.c srcs/block.c

OBJ = $(SRC:.c=.o)

%o: %c
	@gcc -g -o $@ -c $< $(CFLAGS) $(INCL)
	@echo "\033[K\033[34mCompiling\033[00m : \033[32m$^\033[00m"

$(NAME): $(OBJ)
	@cd libft && make
	@gcc $(LIBS) -g -o $(NAME) $(OBJ)
	@echo "\033[K\033[32m$(NAME)\033[00m : \033[34mCreated\033[00m"
	@cp -f $(NAME) players/

all: $(NAME)

clean:
	@cd libft && make clean
	@rm -f $(OBJ)
	@echo "\033[31mClean\033[01m Done\033[00m"

fclean: clean
	@rm -f libft/libftprintf.a
	@rm -f players/$(NAME) $(NAME)
	@echo "\033[31mFclean\033[01m Done\033[00m"

mclean: all clean
	@echo "\033[K\033[33mMake && clean \033[01mDone\033[0m"

re: fclean all
	@echo "\033[32mRe\033[01m Done\033[0m"

.PHONY: all clean fclean mclean re
