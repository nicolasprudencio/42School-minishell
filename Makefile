NAME		=	SEAshell

CC			=	gcc
M_FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g3 -ggdb
FLAGS		=	$(M_FLAGS) $(D_FLAGS)

LEXER_SRCS	=	lexer.c lex_create_terminal.c lex_print_tokens.c
LEXER_SRCS	:=	$(addprefix sources/grammar/lexer/, $(LEXER_SRCS))

GRAM_SRCS	=	define_production.c define_start.c define_terminals.c define_variables.c new.c 
GRAM_SRCS	:=	$(addprefix sources/grammar/grammar_definitions/grammar_,$(GRAM_SRCS))

OBJS_DIR	=	objects
OBJS		=	$(addprefix $(OBJS_DIR)/, $(GRAM_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(LEXER_SRCS:.c=.o))

HEADERS		=	-I./includes -I./libft/header
READLINE	=	-lreadline
LIBFPP		=	-L./libft -lfpp

MAIN		=	main.c

all: fpp_comp $(OBJS) $(NAME)

fpp_comp:
	@make -C libft maths.a
	@make -C libft convert.a
	@make -C libft memory.a
	@make -C libft types.a
	@make -C libft check.a
	@make -C libft printing.a
	@make -C libft printf.a
	@make -C libft data.a
	@make -C libft libfpp.a
	@echo "libfpp compiled"

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(NAME):
	@$(CC) $(FLAGS) $(OBJS) $(MAIN) $(HEADERS) $(LIBFPP) $(READLINE) -o $@

clean:
	@rm -fr objects

fclean: clean
	@rm $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: fpp_comp all clean fclean
