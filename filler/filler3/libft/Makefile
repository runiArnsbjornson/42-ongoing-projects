# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 13:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/04/20 12:43:20 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	handlers/utf8_convert.c \
	Libft/ft_abs.c \
	Libft/ft_atoi.c \
	Libft/ft_bool_strchr.c \
	Libft/ft_bzero.c \
	Libft/ft_ftoa.c \
	Libft/ft_isalnum.c \
	Libft/ft_isalpha.c \
	Libft/ft_isascii.c \
	Libft/ft_isdigit.c \
	Libft/ft_isinf.c \
	Libft/ft_islower.c \
	Libft/ft_isnan.c \
	Libft/ft_isprint.c \
	Libft/ft_isprime.c \
	Libft/ft_isspace.c \
	Libft/ft_isupper.c \
	Libft/ft_itoa.c \
	Libft/ft_itoa_base.c \
	Libft/ft_lpwr.c \
	Libft/ft_lstadd.c \
	Libft/ft_lstdel.c \
	Libft/ft_lstdelone.c \
	Libft/ft_lstiter.c \
	Libft/ft_lstmap.c \
	Libft/ft_lstnew.c \
	Libft/ft_memalloc.c \
	Libft/ft_memccpy.c \
	Libft/ft_memchr.c \
	Libft/ft_memcmp.c \
	Libft/ft_memcpy.c \
	Libft/ft_memdel.c \
	Libft/ft_memmove.c \
	Libft/ft_memset.c \
	Libft/ft_occurence.c \
	Libft/ft_putchar.c \
	Libft/ft_putchar_fd.c \
	Libft/ft_putendl.c \
	Libft/ft_putendl_fd.c \
	Libft/ft_putnbr.c \
	Libft/ft_putnbr_fd.c \
	Libft/ft_putstr.c \
	Libft/ft_putstr_fd.c \
	Libft/ft_puttab.c \
	Libft/ft_puttab_fd.c \
	Libft/ft_pwr.c \
	Libft/ft_replace.c \
	Libft/ft_split.c \
	Libft/ft_sqrt.c \
	Libft/ft_strcat.c \
	Libft/ft_strchr.c \
	Libft/ft_strclr.c \
	Libft/ft_strcmp.c \
	Libft/ft_strcpy.c \
	Libft/ft_strdel.c \
	Libft/ft_strdup.c \
	Libft/ft_strequ.c \
	Libft/ft_stris.c \
	Libft/ft_striter.c \
	Libft/ft_striteri.c \
	Libft/ft_strjoin.c \
	Libft/ft_strlcat.c \
	Libft/ft_strlen.c \
	Libft/ft_strmap.c \
	Libft/ft_strmapi.c \
	Libft/ft_strncat.c \
	Libft/ft_strncmp.c \
	Libft/ft_strncpy.c \
	Libft/ft_strnequ.c \
	Libft/ft_strnew.c \
	Libft/ft_strnjoin.c \
	Libft/ft_strnstr.c \
	Libft/ft_strrealloc.c \
	Libft/ft_strrchr.c \
	Libft/ft_strrev.c \
	Libft/ft_strsplit.c \
	Libft/ft_strstr.c \
	Libft/ft_strsub.c \
	Libft/ft_strtrim.c \
	Libft/ft_tab.c \
	Libft/ft_tabdel.c \
	Libft/ft_tolower.c \
	Libft/ft_toupper.c \
	Libft/ft_wcbytesize.c \
	Libft/ft_wcsbytelen.c \
	Libft/ft_wcscmp.c \
	Libft/ft_wcslen.c \
	Libft/ft_wcsnbytelen.c \
	Libft/ft_wcsnlen.c \
	Libft/get_next_line.c
OBJS = $(SRCS:.c=.o)

INCL = -Iincludes/

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"
	@gcc -g -o $@ -c $< $(CFLAGS) $(INCL)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[0m"

clean:
	@cd Libft && make clean
	@/bin/rm -f $(OBJS)
	@echo "\033[31mRemoval\033[0m  " [ "ft_printf/*.o" ] "  \033[32mComplete\033[0m"

mclean: all clean
	@echo "\033[K\033[32mMake && cleaned\033[00m"

fclean: clean
	@cd Libft && make fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31mRemoval\033[0m" [ $(NAME) ] "\033[32mComplete\033[0m"

re: fclean all
	@echo "\033[K\033[32m*** Let's start anew ***\033[00m"

.PHONY : all clean fclean re
