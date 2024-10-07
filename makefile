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

### LIB ###
DIRLIBFT = ./lib/libft

### SRC ###
SRCDIR = src/
SRC =		main.c \
			Parse/count.c \
			Parse/find_name_later.c \
			Parse/Parsing.c \
			Parse/parsing_tree.c \
			Parse/parsing_tree_tool.c \
			Parse/set_value.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

### OBJ ###
OBJDIR = obj/
PARS_OBJDIR = $(OBJDIR)/Parse
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

### COMPILE ###
CC = cc
CCFLAG = -Wextra -Wall -Werror -g3
INCFLAG = -I$(DIRINC)
LIBFTDIR = lib/libft
PIPEXDIR = pipex/

all:$(NAME)
	@echo "$(tput bold)$(GREEN)$@ is compile$(END)"

libft:
	@if [ ! -f "libft.a" ]; then \
		make -C $(LIBFTDIR) make ;\
		cp $(LIBFTDIR)/libft.a ./; \
	fi;

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CCFLAG) $(INCFLAG) -c $< -o $@
	@echo "$(tput dim) $(MAJA)$<$(END)"

$(NAME): libft $(OBJS)
	$(CC) $(CCFLAG) $(INCFLAG) $(OBJS) src/Parse/libft.a -lreadline -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)objet of $(NAME) is removed$(END)"

fclean: clean
	@rm $(NAME)
	@make -C $(LIBFTDIR) clean
	@echo "$(RED)objet and exec of $(NAME) is removed$(END)"

re: fclean all
	@make -C $(LIBFTDIR) fclean
	@echo $(NAME) is recompiled
