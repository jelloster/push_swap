# ----------FLAGS------------
FLAGS		:= -Wall -Wextra -Werror
DEBUG_FLAGS	:= -g
SANITIZE_FLAGS	:= -g -fsanitize=address

CC		:= cc
SRC_FILES	:= av_handling.c main.c op_ab.c op_a.c		\
		   op_b.c push_swap.c debug.c push_swap_op.c	\
		   push_swap_utils.c stack_utils.c counting_functions.c rotation_counters.c memory_utils.c \
		   more_utils.c rotation_execution.c
OBJ_FILES	:= $(SRC_FILES:.c=.o)
NAME		:= push_swap
LIBFT		:= libft/libft.a

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
