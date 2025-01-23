### WELCOME TO HELL ###


### COLOR ###
RED = \e[31m
MAJA = \e[35m
GREEN = \e[32m
END = \e[0m

### NAME ###
NAME = minishell

### INC ###
DIRINC = ./includes/

### LIB ###
DIRLIBFT = ./lib/libft

### SRC ###
SRCDIR = src/
SRC =		main.c \
			builtins/builtins.c \
			pipex_bonus/pipex_bonus.c \
			pipex_bonus/pipex_bonus_2.c \
			pipex_bonus/my_split.c \
			pipex_bonus/tools.c \
			pipex_bonus/ft_strcmp.c \
			pipex_bonus/check_redirections.c \
			pipex_bonus/tools_built.c \
			pipex_bonus/real_command_builder.c \
			pipex_bonus/real_command_builder_2.c \
			pipex_bonus/tmp_files_fonctions.c \
			pipex_bonus/free_execution_process.c \
			pipex_bonus/tools_heredoc.c \
			pipex_bonus/check_exit.c \
			pipex_bonus/error.c \
			pipex_bonus/error_3.c \
			pipex_bonus/error_2.c \
			pipex_bonus/redirections.c \
			builtins/error.c \
			builtins/cd.c \
			builtins/cd_2.c \
			builtins/echo.c \
			builtins/env.c \
			builtins/exit.c \
			builtins/export.c \
			builtins/pwd.c \
			builtins/unset.c \
			Parse/count.c \
			Parse/checker_syntax.c \
            Parse/checker_syntax_tool.c \
			Parse/dollard.c \
			Parse/dollard_tools.c \
			Parse/find_name_later.c \
			Parse/fill_parsing_tree.c \
			Parse/fill_parsing_tree_rdir.c \
			Parse/Parsing.c \
			Parse/Parsing_tool.c \
			Parse/parsing_tree.c \
			Parse/Parsing_tree_adder.c \
			Parse/parsing_tree_tool.c \
			Parse/quote.c \
			Parse/set_value.c \
			Parse/trim.c \
			Parse/free.c \
			utils/free_all.c \
			utils/signal.c \
			# builtins/tools.c \

SRCS = $(addprefix $(SRCDIR), $(SRC))

### OBJ ###
OBJDIR = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

### COMPILE ###
CC = cc
CCFLAG = -Wall -Werror -Wextra -g3
INCFLAG = -I$(DIRINC)
LIBFTDIR = ./lib/libft/
PIPEXDIR = pipex/

### VAR_BP ###
TOTAL := $(words $(SRCS))
COUNT := 0

all: progress $(NAME)
	@echo "$(tput bold)$(GREEN)\n$(NAME) is compile$(END)";

libft:
	@if [ ! -f "libft.a" ]; then \
		make -s -C $(LIBFTDIR) all > /dev/null;\
		cp $(LIBFTDIR)libft.a ./; \
	fi;

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@printf "\r[%-$(TOTAL)s] $(COUNT)/$(TOTAL)" $$(printf '#%.0s' $$(seq 1 $(COUNT)))
	@mkdir -p $(dir $@) > /dev/null
	@$(CC) $(CCFLAG) $(INCFLAG) -c $< -o $@

progress:
	@if [ ! -f "$(NAME)" ]; then \
		echo "Compilation in progress..." ;\
		printf "\r[%-$(TOTAL)s] 0/$(TOTAL)";\
	fi;

$(NAME): libft $(OBJS)
	@$(CC) $(CCFLAG) $(INCFLAG) $(OBJS) libft.a -lreadline -o $@

val: all
	valgrind ./$(NAME)

clean:
	@rm -rf $(OBJDIR)
	@rm -f libft.a
	@echo "$(RED)objet of $(NAME) is removed$(END)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) clean
	@echo "$(RED)objet and exec of $(NAME) is removed$(END)"

re: fclean all
	@make -C $(LIBFTDIR) fclean
	@echo $(NAME) is recompiled

.PHONY: all clean fclean re progess
