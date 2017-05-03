# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 15:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/05/03 13:09:44 by jdebladi         ###   ########.fr        #
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

INCL = -I includes -I libft/libft

LIBS = -Llibft -lftprintf

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_G)

%o: %c
	@gcc -g -o $@ -c $< $(CFLAGS) $(INCL)
	@echo "\033[K\033[34mCompiling\033[00m : \033[32m$^\033[00m"

$(NAME): $(OBJ)
	@cd libft && make
	@gcc $(LIBS) -g -o $(NAME) $(OBJ) $(INCL)
	@echo "\033[K\033[32m$(NAME)\033[00m : \033[34mCreated\033[00m"
	@cp -f $(NAME) players/

$(NAME_G): $(OBJ_G)
	@cd libft && make
	@gcc $(LIBS) -g -o $(NAME_G) $(OBJ_G) $(INCL)
	@echo "\033[K\033[32m$(NAME_G)\033[00m : \033[34mCreated\033[00m"
	@cp -f $(NAME_G) players/

clean:
	@cd libft && make clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_G)
	@echo "\033[31mClean\033[01m Done\033[00m"

fclean: clean
	@rm -f libft/libftprintf.a
	@rm -f players/$(NAME) $(NAME)
	@rm -f players/$(NAME_G) $(NAME_G)
	@echo "\033[31mFclean\033[01m Done\033[00m"

mclean: all clean
	@echo "\033[K\033[33mMake && clean \033[01mDone\033[0m"

re: fclean all
	@echo "\033[32mRe\033[01m Done\033[0m"

.PHONY: all clean fclean mclean re
