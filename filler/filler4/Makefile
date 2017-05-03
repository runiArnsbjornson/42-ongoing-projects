# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 15:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/05/02 17:19:51 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jdebladi.filler

NAME_G = jdebladi.filler.g

SRC_DIR = srcs/

FILE = filler.c search.c display.c block.c 

SRC = $(addprefix $(SRC_DIR), $(FILE)) srcs/main.c

SRC_G = $(addprefix $(SRC_DIR), $(FILE)) srcs/main_g.c

OBJ = $(SRC:.c=.o)

OBJ_G = $(SRC_G:.c=.o)

INCL = -I includes

LIBS = -Llibft -lftprintf

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_G)

%o: %c
	@gcc -g -o $@ -c $< $(CFLAGS) $(INCL)
	@echo "\033[K\x1B[34mCompiling\x1B[00m : \x1B[32m$^\x1B[00m"

$(NAME): $(OBJ)
	@cd libft && make
	@gcc $(LIBS) -g -o $(NAME) $(OBJ)
	@echo "\x1B[K\x1B[32m$(NAME)\x1B[00m : \x1B[34mCreated\x1B[00m"
	@cp -f $(NAME) players/

$(NAME_G): $(OBJ_G)
	@cd libft && make
	@gcc $(LIBS) -g -o $(NAME_G) $(OBJ_G)
	@echo "\x1B[K\x1B[32m$(NAME_G)\x1B[00m : \x1B[34mCreated\x1B[00m"
	@cp -f $(NAME_G) players/

clean:
	@cd libft && make clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_G)
	@echo "\x1B[31mClean\x1B[01m Done\x1B[00m"

fclean: clean
	@rm -f libft/libftprintf.a
	@rm -f players/$(NAME) $(NAME)
	@rm -f players/$(NAME_G) $(NAME_G)
	@echo "\x1B[31mFclean\x1B[01m Done\x1B[00m"

mclean: all clean
	@echo "\x1B[K\x1B[33mMake && clean \x1B[01mDone\x1B[0m"

re: fclean all
	@echo "\x1B[32mRe\x1B[01m Done\x1B[0m"

.PHONY: all clean fclean mclean re
