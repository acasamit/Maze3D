# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:04:03 by vcornill          #+#    #+#              #
#    Updated: 2024/03/14 17:38:10 by vcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

MLX_DIR = MLX42
LIBFT_DIR = ft_printf/libft
FT_PRINTF_DIR = ft_printf

MLX = $(MLX_DIR)/build/libmlx42.a
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS =	-g -Wall -Wextra -Werror \
			-I$(MLX_DIR)/include/MLX42 \
			-I$(LIBFT_DIR) \
			-I$(FT_PRINTF_DIR)
LFLAGS =	-L$(MLX_DIR)/build \
			-L$(LIBFT_DIR) \
			-L$(FT_PRINTF_DIR) \
			-lmlx42 -lft -lftprintf -lglfw -ldl -lm

FILES = utils_parsing_color utils_parsing_path raycast key draw main error parsing utils_general utils_parsing utils_map_checker init_game

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix src/, $(addsuffix .o, $(FILES)))

all: $(NAME)

clean :
	@rm -rf $(OBJS)
	@make fclean -C $(FT_PRINTF_DIR)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 

$(NAME): $(MLX) $(LIBFT) $(FT_PRINTF) $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LFLAGS)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
