CC = gcc
SRC = bsq.c \
	check_map.c \
	ft_atoi.c \
	ft_display.c \
	ft_putchar.c \
	ft_resolve.c \
	ft_split.c \
	ft_str_nb_line.c \
	ft_strcut.c \
	ft_strdup.c \
	ft_strlen.c \

OBJ = $(SRC:.c=.o)
INCL = bsq.h
NAME = bsq
CFLAGS = -Wall -Wextra -Werror -I $(INCL)

all : $(NAME)

%.o: %.c
	@$(CC) -g -o $@ -c $< $(CFLAGS)

$(NAME) : $(OBJ)
	@echo "et hop"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean :
	@echo "hop on efface"
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
	@echo "et on recommence"

.PHONY : all clean fclean re
