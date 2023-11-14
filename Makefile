#INITIAL CONFIG
NAME		= minishell
CC			= cc
C_FLAGS		= -Werror -Wextra -Wall -g
INCLUDE		= -I./includes

#REGEXP
ANSI		=	\033[0
YELLOW		=	;33
GREEN		=	;32
RED			=	;31

#LIBFT
LFT_PTH		=  utils/libft
LFT_LINK	= -L./$(LFT_PTH) -lft
INCLUDE		+= -I./$(LFT_PTH)/includes

#SOURCE
S_PTH		= srcs/
LEX_PTH	= $(S_PTH)parser/
S_FILES		= lexer.c
SRCS		+= $(addprefix $(LEX_PTH), $(S_FILES))

#OBJECTS
OBJS		= objs/$(SRCS:.c=.o)

#MAIN
MAIN		= main.c

all: libft $(NAME)

objs/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(MAIN)
	@$(CC) $(C_FLAGS) $(OBJS) $(MAIN) $(INCLUDE) $(LFT_LINK) -o $@
	@printf "%s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "minishell:" "Compiled"

libft:
	@make -C $(LFT_PTH)

clean:
	@rm -fr objs

fclean:
	@rm -fr minishell
	@make -C $(LFT_PTH) fclean

re: fclean all
