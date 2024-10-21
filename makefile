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
<<<<<<< HEAD
			error.c \
=======
			execute.c \
			builtins/builtins.c \
			pipex_bonus/pipex_bonus.c \
			pipex_bonus/split.c \
			pipex_bonus/tools.c \
			builtins/error.c \
			builtins/cd.c \
			builtins/tools.c \
			builtins/echo.c \
			builtins/env.c \
			builtins/export.c \
			builtins/pwd.c \
			builtins/unset.c \
>>>>>>> origin/raphaelmain
			Parse/count.c \
			Parse/find_name_later.c \
			Parse/Parsing.c \
			Parse/parsing_tree.c \
			Parse/parsing_tree_tool.c \
			Parse/set_value.c \
<<<<<<< HEAD
			Parse/checker_syntax.c \
			Parse/free.c \
=======
>>>>>>> origin/raphaelmain

SRCS = $(addprefix $(SRCDIR), $(SRC))

### OBJ ###
OBJDIR = obj/
PARS_OBJDIR = $(OBJDIR)/Parse
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

### COMPILE ###
<<<<<<< HEAD
CC = cc
CCFLAG = -Wextra -Wall -g3
INCFLAG = -I$(DIRINC)
LIBFTDIR = ./lib/libft/
PIPEXDIR = pipex/

all:$(NAME)
	@echo "$(tput bold)$(GREEN)$@ is compile$(END)";
=======
CC = gcc -no-pie
CCFLAG = -g3
INCFLAG = -I$(DIRINC)
LIBFTDIR = ./lib/libft/
PIPEXLIB = ./pipex_bonus/
PIPEXDIR = pipex/

all:$(NAME)
	@echo "$(tput bold)$(GREEN)$ All is compiled$(END)"
>>>>>>> origin/raphaelmain

libft:
	@if [ ! -f "libft.a" ]; then \
		make -C $(LIBFTDIR) all ;\
<<<<<<< HEAD
		cp $(LIBFTDIR)libft.a ./; \
=======
		cp $(LIBFTDIR)libft.a ./;\
>>>>>>> origin/raphaelmain
	fi;

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CCFLAG) $(INCFLAG) -c $< -o $@
	@echo "$(tput dim) $(MAJA)$<$(END)"

$(NAME): libft $(OBJS)
	@$(CC) $(CCFLAG) $(INCFLAG) $(OBJS) libft.a -lreadline -o $@

clean:
	@rm -rf $(OBJDIR)
	@rm libft.a
	@echo "$(RED)objet of $(NAME) is removed$(END)"

fclean: clean
	@rm $(NAME)
	@make -C $(LIBFTDIR) clean
	@echo "$(RED)objet and exec of $(NAME) is removed$(END)"

re: fclean all
	@make -C $(LIBFTDIR) fclean
<<<<<<< HEAD
=======
	@echo $(NAME) is recompiled
>>>>>>> origin/raphaelmain
