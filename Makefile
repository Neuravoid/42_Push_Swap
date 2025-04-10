# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 19:32:53 by ualkan            #+#    #+#              #
#    Updated: 2025/03/25 19:33:28 by ualkan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

define HEADER
	@echo "╔═══════════════════════════════════════════════╗"
	@echo "║         🌀 PUSH_SWAP PROJECT BUILD 🌀         ║"
	@echo "║         By ualkan ~ 42 Istanbul Edition       ║"
	@echo "╚═══════════════════════════════════════════════╝"
endef

SRCS = main.c \
	error_handle.c \
	free.c \
	init_nodes_a.c \
	init_nodes_b.c \
	move_1.c \
	move_2.c \
	split.c \
	stack_init.c \
	turkish_sort.c \
	utils_1.c \
	utils_2.c \
	utils_3.c 

BONUS_SRCS = checker_bonus.c \
	error_bonus.c \
	free_bonus.c \
	init_bonus.c \
	move_1_bonus.c \
	move_2_bonus.c \
	split_bonus.c \
	utils_bonus.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c


BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

HEADER:
	$(HEADER)

$(NAME): $(OBJS)
	@echo "🔨 Building $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	@echo "🔨 Building bonus: $(BONUS)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

clean:
	@echo "🧹 Cleaning objects..."
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "🧼 Removing executables..."
	@rm -f $(NAME) $(BONUS)

re: fclean all

set: HEADER fclean all bonus
	@rm -f $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re set bonus HEADER
