NAME		=	SEAshell

CC		=	gcc
M_FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g3 -ggdb
FLAGS		=	$(M_FLAGS) $(D_FLAGS)

CORE		=	core.c
CORE		:=	$(addprefix sources/, $(CORE))

UTILS		=	is_builtin.c is_flag.c str_is_enclosed.c put_cmdt.c var_exists.c
UTILS		+=	char_exists.c str_len_until.c is_terminal.c ft_itoa.c
UTILS		:=	$(addprefix utilities/, $(UTILS))

LEXER_SRCS	=	lexer.c token_new.c put_token.c token_push_last.c token_last_is_pipe.c
LEXER_SRCS	+=	token_add_string.c token_add_terminal.c token_add_special.c token_add_flag.c
LEXER_SRCS	+=	expand_variable.c is_valid_env.c
LEXER_SRCS	:=	$(addprefix sources/lexer/, $(LEXER_SRCS))

PARSE_SRCS	=	parser.c
PARSE_SRCS	:=	$(addprefix sources/parser/, $(PARSE_SRCS))

SIGNAL_SRCS	=	signals.c signals_heredoc.c
SIGNAL_SRCS	:=	$(addprefix sources/signals/, $(SIGNAL_SRCS))

AUT_SRCS	=	act.c find_transition.c new.c transition_relation.c find_command.c
AUT_SRCS	+=	restart_stack.c find_state.c
AUT_SRCS	:=	$(addprefix sources/parser/automaton_, $(AUT_SRCS))

CMDT_SRCS	=	create.c destroy.c
CMDT_SRCS	:=	$(addprefix sources/parser/cmdt_, $(CMDT_SRCS))

CMD_SRCS	=	pipe.c iredir.c oredir.c append.c heredoc.c create.c last.c
CMD_SRCS	:=	$(addprefix sources/parser/cmd_, $(CMD_SRCS))

GRAM_SRCS	=	define_production.c define_terminals.c define_variables.c new.c 
GRAM_SRCS	:=	$(addprefix sources/grammar_definitions/grammar_,$(GRAM_SRCS))

EXEC_SRCS	=	.c _cd.c _echo.c _env.c _export.c _pwd.c _unset.c _open_process.c _exit.c
EXEC_SRCS	:=	$(addprefix sources/exec/exec, $(EXEC_SRCS))

OBJS_DIR	=	objects
OBJS		=	$(addprefix $(OBJS_DIR)/, $(CORE:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(GRAM_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(LEXER_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(EXEC_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(AUT_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(UTILS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(SIGNAL_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(CMDT_SRCS:.c=.o))
OBJS		+=	$(addprefix $(OBJS_DIR)/, $(CMD_SRCS:.c=.o))

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
	@echo -e "\t      Â      ___ ___   _       _        _ _"
	@echo -e "\t    _{ }    / __| __| /_\   __| |_  ___| | |"
	@echo -e "\t  _(  | )   \__ \ _| / _ \ (_-< ' \/ -_) | |"
	@echo -e "\t_{__(}  _}  |___/___/_/ \_\/__/_||_\___|_|_|"
	@echo "       (    /     )"
	@echo "      { __()__  _ _} -42 school project minishell-"
	@echo "     {(_( )      _ ()"
	@echo "      (  {}_   _/  --\\_"
	@echo "       (  |    ( - - - \\"
	@echo -e "\t(__|_ _|- -- -_)"
	@echo -e "\t    \\   ( --_)"
	@echo -e "\t     |  (|_)"
	@echo -e "\t     L_ (|) by: Fauna Polaris"
	@echo -e "\t      \\_|)             && Nicolas Prudencio"
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
