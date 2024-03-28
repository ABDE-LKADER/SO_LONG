# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/03/27 15:51:34 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	mandatory/moves.c   \
				mandatory/so_long.c  \
				mandatory/parce_in.c  \
				mandatory/mlx_init.c   \
				mandatory/load_png.c    \
				mandatory/set_keys.c     \
				mandatory/mlx_space.c

OBJS		=	$(SRCS:.c=.o)

HEADER		=	mandatory/so_long.h

MYLB		=	MYLIB
MYAR		=	MYLIB/libar.a

FLAGS		=	cc -Wall -Wextra -Werror
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(MYLB) $(NAME)
	@echo $(GREEN)Done !!$(RESET)

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	@$(FLAGS) $^ -L$(MYLB) -lar -L.MLX42/build -lmlx42 -L/Users/abadouab/.brew/opt/glfw/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	@printf "\n"

# $(FLAGS) $^ -L$(MYLB) -lar -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): %.o: %.c $(HEADER) $(MYAR)
	@$(FLAGS) -c -I $(MYLB) -I .MLX42/include/MLX42 $< -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(MYLB) --no-print-directory
	@echo $(YELOW)Done !!$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(MYLB) --no-print-directory
	@echo $(REDCL)Done !!$(RESET)

re: fclean all

.PHONY: $(MYLB)
