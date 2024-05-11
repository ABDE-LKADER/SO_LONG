# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/05/11 20:43:42 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long
NAME_BONUS				=	so_long_bonus

SRCS				=	mandatory/so_long.c  \
						mandatory/mlx_plus.c  \
						mandatory/mlx_parce.c  \
						mandatory/mlx_tools.c   \
						mandatory/mlx_space.c    \
						mandatory/moving_up.c     \
						mandatory/moving_down.c    \
						mandatory/moving_left.c     \
						mandatory/moving_right.c     \
						mandatory/exit_sprites.c      \
						mandatory/fire_sprites.c       \
						mandatory/idle_sprites.c

SRCS_BONUS			=	bonus/so_long.c  \
						bonus/mlx_plus.c  \
						bonus/mlx_parce.c  \
						bonus/mlx_tools.c   \
						bonus/mlx_space.c    \
						bonus/moving_up.c     \
						bonus/moving_down.c    \
						bonus/moving_left.c     \
						bonus/moving_right.c     \
						bonus/exit_sprites.c      \
						bonus/fire_sprites.c       \
						bonus/idle_sprites.c

OBJS				=	$(SRCS:.c=.o)
OBJS_BONUS			=	$(SRCS_BONUS:.c=.o)

HEADER				=	mandatory/so_long.h
HEADER_BONUS		=	mandatory/so_long.h

MYLB		=	MYLIB
MYAR		=	MYLIB/libar.a
MLX			=	mlx

FLAGS		=	cc -Wall -Wextra -Werror
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: start $(MYLB) $(NAME) finish

start:
	@printf "\n"
	@echo $(GREEN)"Starting build..."
	@sleep 1
	@printf "Loading [ "

finish:
	@echo $(GREEN) ] 100%$(RESET)
	@echo $(GREEN)Project built.$(RESET)
	@printf "\n"

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	@$(FLAGS) $^ -L$(MYLB) -lar -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): %.o: %.c $(HEADER) $(MYAR) $(MXAR)
	@$(FLAGS) -c -I $(MYLB) -I $(MLX) $< -o $@
	@printf $(GREEN)"."$(RESET)

bonus:  start $(MYLB) $(NAME_BONUS) finish

$(NAME_BONUS): $(OBJS_BONUS)
	@$(FLAGS) $^ -L$(MYLB) -lar -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

$(OBJS_BONUS): %.o: %.c $(HEADER) $(MYAR) $(MXAR)
	@$(FLAGS) -c -I $(MYLB) -I $(MLX) $< -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -C $(MYLB) --no-print-directory
	@echo $(YELOW)Cleaning up 🧹💫$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make fclean -C $(MYLB) --no-print-directory
	@echo $(REDCL)Purging all files 🗑️$(RESET)

re: fclean all

.PHONY: $(MYLB)
