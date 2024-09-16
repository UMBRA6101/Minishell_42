### WELCOME TO HELL ###


### COLOR ###
RED = \e[31m
MAJA = \e[35m
GREEN = \e[32m
END = \e[0m


### NAME ###
NAME = Minishell

### INC ###
DIRINC = ./includes/

### SRC ###
SRCDIR = src/
SRC =	main.c \

SRCS = $(addprefix $(SRCDIR), $(SRC))

### OBJ ###
OBJDIR = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

### COMPILE ###
CC = cc
CCFLAG = -Wextra -Wall -Werror -g3
INCFLAG = -I$(DIRINC)
LIBFTDIR = libft/
PIPEXDIR = pipex/

all:$(NAME)
	@echo "$(tput bold)$(GREEN)$@ is compile$(END)"

$(OBJS): $(SRCS)
	@$(CC) $(CCFLAG) $(INCFLAG) -c $< -o $@
	@echo "$(tput dim) $(MAJA)$<$(END)"

$(NAME): $(OBJS)
	@$(CC) $(CCFLAG) $(INCFLAG) $(OBJS) -o $@ -lreadline

clean:
	@rm $(OBJS)
	@echo "$(RED)objet of $(NAME) is removed$(END)"

fclean: clean
	@rm $(NAME)
	@echo "$(RED)objet and exec of $(NAME) is removed$(END)"

re: fclean all
	@echo $(NAME) is recompiled