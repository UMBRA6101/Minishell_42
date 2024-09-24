### WELCOME TO HELL ###


### COLOR ###
RED = \e[31m
MAJA = \e[35m
GREEN = \e[32m
END = \e[0m


### NAME ###
NAME = Minishell

### INC ###
DIRINC = ../../includes/

### LIB ###
DIRLIBFT = ./lib/libft

### SRC ###
SRC =	find_name_later.c \
		count.c \
		set_value.c \
		Parsing.c \

### OBJ ###
OBJDIR = obj/
OBJ = $(SRC:.c=.o)

### COMPILE ###
CC = cc
CCFLAG = -Wextra -Wall -Werror -g3
INCFLAG = -I$(DIRINC)
LIBFTDIR = libft/

all:$(NAME)

$(OBJ): $(SRC)
	$(CC) $(CCFLAG) $(INCFLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CCFLAG) $(INCFLAG) $(OBJ) -libft.a -o $@ -lreadline

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
	echo $(NAME) is recompiled