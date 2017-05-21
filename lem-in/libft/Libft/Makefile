# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:34:05 by jdebladi          #+#    #+#              #
#    Updated: 2017/05/19 14:08:09 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCL = .

CFLAGS = -Wall -Wunused -Wextra -Werror -Weverything -fdiagnostics-show-option

SRC = ft_abs.c \
	ft_atoi.c \
	ft_bool_strchr.c \
	ft_bzero.c \
	ft_ftoa.c \
	ft_gnl.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isinf.c \
	ft_islower.c \
	ft_isnan.c \
	ft_isprint.c \
	ft_isprime.c \
	ft_isspace.c \
	ft_isupper.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_lpwr.c \
	ft_lstadd.c \
	ft_lstaddend.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_occurence.c \
	ft_put_error.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_puttab.c \
	ft_puttab_fd.c \
	ft_pwr.c \
	ft_replace.c \
	ft_split.c \
	ft_sqrt.c \
	ft_strcat.c \
	ft_strccpy.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_stris.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnjoin.c \
	ft_strnstr.c \
	ft_strrealloc.c \
	ft_strrchr.c \
	ft_strrev.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtol.c \
	ft_strtrim.c \
	ft_tab.c \
	ft_tabdel.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_wcbytesize.c \
	ft_wcsbytelen.c \
	ft_wcscmp.c \
	ft_wcslen.c \
	ft_wcsnbytelen.c \
	ft_wcsnlen.c \
	get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"
	@gcc -g -o $@ -c $< $(CFLAGS) -I $(INCL)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31mClean \033[32mDone\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mFclean\033[32m Done\033[0m"

re: 
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "\033[32m*** Re Done ***\033[00m"

.PHONY : all clean fclean re
