NAME		=	SEAshell

CC			=	gcc
M_FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g3 -ggdb
FLAGS		=	$(M_FLAGS) $(D_FLAGS)

UTILS		=	char_exists.c is_terminal.c is_flag.c str_is_enclosed.c env_expand_variables.c str_comp_upto.c str_comp_until.c str_len_until.c environment.c
UTILS		:=	$(addprefix utilities/, $(UTILS))

LEXER_SRCS	=	lexer.c token_new.c put_token.c token_push_last.c
LEXER_SRCS	:=	$(addprefix sources/grammar/lexer/, $(LEXER_SRCS))

PARSE_SRCS	=	parser.c
PARSE_SRCS	:=	$(addprefix sources/grammar/parser/, $(PARSE_SRCS))

AUT_SRCS	=	act.c astates.c find_transition.c new.c states.c transition_relation.c
AUT_SRCS	:=	$(addprefix sources/grammar/parser/automaton_, $(AUT_SRCS))

BUILT_SRCS	= exec_cd.c exec_echo.c exec_env.c exec_export.c exec_pwd.c exec_unset.c
BUILT_SRCS	:= $(addprefix sources/builtins/, $(BUILT_SRCS))

HERE_SRCS	=	heredoc.c
HERE_SRCS	:=	$(addprefix sources/heredoc/, $(HERE_SRCS))

GRAM_SRCS	=	define_production.c define_terminals.c define_variables.c new.c 
GRAM_SRCS	:=	$(addprefix sources/grammar/grammar_definitions/grammar_,$(GRAM_SRCS))

OBJS_DIR	=	objects
OBJS		=	$(addprefix $(OBJS_DIR)/, $(GRAM_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(LEXER_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(AUT_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(UTILS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(BUILT_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(HERE_SRCS:.c=.o))

HEADERS		=	-I./includes -I./libft/header
READLINE	=	-lreadline
LIBFPP		=	-L./libft -lfpp

GREEN		=	\033[0;32m
BLUE		=	\033[0;1;34m
RESET		=	\033[0m

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
	@make -C libft stack.a
	@make -C libft libfpp.a
	@echo "libfpp compiled"

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(NAME):
	@printf "$(GREEN)%s$(RESET) %30s\n" "Compiling" "SEAshell"
	@printf "%-15s\n" "-----"
	@printf "Available commands:\n\n"
	@printf "$(BLUE)test$(RESET)  = shows the grammar rules\n"
	@printf "$(BLUE)exit$(RESET)  = finishes the program execution\n"
	@printf "%-15s\n" "-----"
	@$(CC) $(FLAGS) $(OBJS) $(MAIN) $(HEADERS) $(LIBFPP) $(READLINE) -o $@

clean:
	@rm -fr objects

fclean: clean
	@rm $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: fpp_comp all clean fclean
