#INITIAL CONFIG
NAME	= minishell
CC		= cc
C_FLAGS	= -Werror -Wextra -Wall -g
INCLUDE = -I./includes

#REGEXP
ANSI		=	\033[0
YELLOW		=	;33
GREEN		=	;32
RED			=	;31

#LIBFT

LFT_PTH =  /utils/libft
LFT_LINK = $(LFT_PATH)/includes -lm -lft
INCLUDE += -I.$(LFT_PTH)

#SOURCE
S_PATH	= srcs/
S_FILES = lexer.c
SRCS	+= $(addprefix $(S_PATH), $(S_FILES))

#OBJECTS
OBJS	= objs/$(SRCS:.c=.o)

#MAIN

MAIN = main.c

all: $(NAME)

objs/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME):
	@$(CC) $(C_FLAGS) $(OBJS) $(MAIN) $(INCLUDE) $(LFT_LINK) -o $@
	@printf "%s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "push_swap:" "Compiled"

libft:
	@make -C $(LFT_PTH)

clean:
	@rm -fr objs

fclean:
	@rm -fr minishell
	@make -C $(LFT_PTH) fclean

re:
	fclean all
