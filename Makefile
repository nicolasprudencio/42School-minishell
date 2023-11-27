NAME		=	SEAshell

CC		=	gcc
M_FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g3 -ggdb
FLAGS		=	$(M_FLAGS) $(D_FLAGS)

HEADERS		=	-I./includes -I./libft/header
READLINE	=	-lreadline
LIBFPP		=	-L./libft -lfpp

MAIN		=	main.c

all: fpp_comp $(NAME)

fpp_comp:
	@make -C libft memory.a
	@make -C libft types.a
	@make -C libft libfpp.a
	@echo "libfpp compiled"


$(NAME):
	$(CC) $(FLAGS) $(MAIN) $(HEADERS) $(LIBFPP) $(READLINE) -o $@

clean:

fclean: clean
	@rm $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: fpp_comp all clean fclean all
