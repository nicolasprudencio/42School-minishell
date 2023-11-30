NAME		=	SEAshell

CC		=	gcc
M_FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g3 -ggdb
FLAGS		=	$(M_FLAGS) $(D_FLAGS)

GRAM_SRCS	=	define_production.c define_start.c define_terminals.c define_variables.c new.c 
GRAM_SRCS	=	$(addprefix sources/grammar/grammar_,$(GRAM_SRCS))

GRAM_OBJS	=	$(GRAM_SCRS:.c=.o)

OBJS_DIR	=	objects
OBJS		=	$(addprefix $(OBJS_DIR)/, $(GRAM_OBJS))

HEADERS		=	-I./includes -I./libft/header
READLINE	=	-lreadline
LIBFPP		=	-L./libft -lfpp

MAIN		=	main.c

all: fpp_comp $(OBJS) $(NAME)

fpp_comp:
	@make -C libft memory.a
	@make -C libft types.a
	@make -C libft libfpp.a
	@echo "libfpp compiled"

$(OBJS_DIR)/%.c:.o
	@mkdir -p $(@D)
	$(CC) $(C_FLAGS) -c $< -o $@ $(HEADERS)

$(NAME):
	@$(CC) $(FLAGS) $(OBJS) $(MAIN) $(HEADERS) $(LIBFPP) $(READLINE) -o $@

clean:

fclean: clean
	@rm $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: fpp_comp all clean fclean all
