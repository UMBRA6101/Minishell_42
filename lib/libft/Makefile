# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 16:39:09 by thodos-s          #+#    #+#              #
#    Updated: 2023/11/20 15:18:56 by thodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilateur et regles de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./ 

# Tout les .c qu'on souhaite compiler
SOURCES =  $(wildcard src/*.c)

# Tout les .c qu'on souhaite compiler en .o
OBJECTS = $(SOURCES:.c=.o)

# .h qu'on souhaite intégrer à l'éxécutable
HEADER = libft.h 

# nom de la bibliotheque / du projet
TARGET = libft.a

AR = ar rc

# Demande à tout compiler lorsque l'on utilisera la commande make
all: $(TARGET)

so:
	@$(CC) -fPIC $(CFLAGS) -c $(SOURCES)  # Compilation des fichiers sources en fichiers objets
	@$(CC) -shared -o libft.so $(OBJECTS)  # Création de la bibliothèque partagée


# règles de compilation des .c en .o
main.o: main.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# règles de compilation de l'éxécutable
$(TARGET): $(OBJECTS)
	@ar rcs $@ $^
	@make -C ft_printf all && cp ./ft_printf/ft_printf.a ./$@

# Nettoyer les .o compilés
clean:
	rm -f $(OBJECTS)
	make -C ft_printf clean

# Commande pour nettoyer les .o et l'éxécutable
fclean: clean
	rm -f $(TARGET)
	make -C ft_printf fclean


# Re-Build tout le projet
re: fclean all

# La commande PHONY indique au programme de ne pas prendre en compte
# les commandes suivantes comme des objets utiles à la compilation
.PHONY: all clean fclean re
