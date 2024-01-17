NAME		=	SEAshell

CC		=	gcc
M_FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g3 -ggdb
FLAGS		=	$(M_FLAGS) $(D_FLAGS)

UTILS		=	is_terminal.c is_flag.c str_is_enclosed.c str_comp_upto.c put_cmdt.c
UTILS		:=	$(addprefix utilities/, $(UTILS))

LEXER_SRCS	=	lexer.c token_new.c put_token.c token_push_last.c token_last_is_pipe.c
LEXER_SRCS	:=	$(addprefix sources/grammar/lexer/, $(LEXER_SRCS))

PARSE_SRCS	=	parser.c
PARSE_SRCS	:=	$(addprefix sources/grammar/parser/, $(PARSE_SRCS))

AUT_SRCS	=	act.c astates.c find_transition.c new.c transition_relation.c find_command.c
AUT_SRCS	+=	restart_stack.c find_state.c cmdt_create.c cmd_create.c cmd_add.c cmd_last.c
AUT_SRCS	+=	cmd_destroy.c cmd_pipe.c
AUT_SRCS	:=	$(addprefix sources/grammar/parser/automaton_, $(AUT_SRCS))

GRAM_SRCS	=	define_production.c define_terminals.c define_variables.c new.c 
GRAM_SRCS	:=	$(addprefix sources/grammar/grammar_definitions/grammar_,$(GRAM_SRCS))

OBJS_DIR	=	objects
OBJS		=	$(addprefix $(OBJS_DIR)/, $(GRAM_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(LEXER_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(AUT_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(UTILS:.c=.o))

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
	@$(CC) $(FLAGS) $(OBJS) $(MAIN) $(HEADERS) $(LIBFPP) $(READLINE) -o $@
	@echo
	@echo "\t      Â      ___ ___   _       _        _ _"
	@echo "\t    _{ }    / __| __| /_\   __| |_  ___| | |"
	@echo "\t  _(  | )   \__ \ _| / _ \ (_-< ' \/ -_) | |"
	@echo "\t_{__(}  _}  |___/___/_/ \_\/__/_||_\___|_|_|"
	@echo "       (    /     )"
	@echo "      { __()__  _ _} -42 school project minishell-"
	@echo "     {(_( )      _ ()"
	@echo "      (  {}_   _/  --\\_"
	@echo "       (  |    ( - - - \\"
	@echo "\t(__|_ _|- -- -_)"
	@echo "\t    \\   ( --_)"
	@echo "\t     |  (|_)"
	@echo "\t     L_ (|) by: Fauna Polaris"
	@echo "\t      \\_|)             || Nicolas Prudencio"
	@echo

clean:
	@rm -fr objects

fclean: clean
	@rm $(NAME)
	@make -C libft fclean

recompile: clean
	@rm $(NAME)
	@make

re: fclean all

.PHONY: fpp_comp all clean fclean
