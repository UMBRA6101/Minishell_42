# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raphox <raphox@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 16:39:09 by thodos-s          #+#    #+#              #
#    Updated: 2024/10/08 15:13:04 by raphox           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \e[32m
END = \e[0m

# Compilateur et regles de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./


# Tout les .c qu'on souhaite compiler
SRCDIR = src/
SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd_back_bonus.c \
           ft_lstadd_front_bonus.c \
           ft_lstclear_bonus.c \
           ft_lstdelone_bonus.c \
           ft_lstlast_bonus.c \
           ft_lstmap_bonus.c \
           ft_lstnew_bonus.c \
           ft_lstsize_bonus.c \
           ft_lststiter_bonus.c \
           ft_memchr.c \
           ft_memcmp.c \
           ft_memcpy.c \
           ft_memmove.c \
           ft_memset.c \
           ft_putchar_fd.c \
           ft_putendl_fd.c \
           ft_putnbr_fd.c \
           ft_putstr_fd.c \
           ft_split.c \
           ft_strchr.c \
           ft_strdup.c \
           ft_striteri.c \
           ft_strjoin.c \
           ft_strlcat.c \
           ft_strlcpy.c \
           ft_strlen.c \
           ft_strmapi.c \
           ft_strncmp.c \
           ft_strnstr.c \
           ft_strrchr.c \
           ft_strtrim.c \
           ft_substr.c \
           ft_tolower.c \
           ft_toupper.c \
           get_next_line.c \
           get_next_line_utils.c \
           ft_strtok.c \
           ft_strcspn.c \

SRCS = $(addprefix $(SRCDIR), $(SRC))
# Tout les .c qu'on souhaite compiler en .o
OBJ = $(SRCS:.c=.o)

# .h qu'on souhaite intégrer à l'éxécutable
HEADER = libft.h 

# nom de la bibliotheque / du projet
NAME = libft.a

AR = ar rc

# Demande à tout compiler lorsque l'on utilisera la commande make
all: $(NAME)
	@echo "$(tput bold)$(GREEN)$(TARGET) is compile$(END)"

%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# règles de compilation de l'éxécutable
$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $(NAME)
	@make -C ft_printf all && cp ./ft_printf/ft_printf.a ./$@

# Nettoyer les .o compilés
clean:
	@rm -f $(OBJ)
	@make -C ft_printf clean

# Commande pour nettoyer les .o et l'éxécutable
fclean: clean
	@rm -f $(NAME)
	@make -C ft_printf fclean


# Re-Build tout le projet
re: fclean all

# La commande PHONY indique au programme de ne pas prendre en compte
# les commandes suivantes comme des objets utiles à la compilation
.PHONY: all clean fclean re