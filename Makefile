# ----------FLAGS------------
FLAGS		:=	-Wall -Wextra -Werror
DEBUG_FLAGS	:=	-g
SANITIZE_FLAGS	:=	-g -fsanitize=address

CC			:=	cc
SRC_FILES	:=	index_functions.c  main.c  push_swap.c  push_swap_op.c	\
				rotation_counters.c  rotation_execution.c av_handling.c	\
				stack_utils.c debug.c double_op.c free_and_exit.c
OBJ_FILES	:=	$(SRC_FILES:.c=.o)
NAME		:=	push_swap
LIBFT		:=	libft/libft.a

# -------------RULES--------------

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) -o $@ $^

$(OBJ_FILES): %.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

# ----------- PHONIES ------------

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) 

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: mc
mc: all clean

.PHONY: debug
debug: FLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: sanitize
sanitize: FLAGS += $(SANITIZE_FLAGS)
sanitize: re
