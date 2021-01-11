# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 19:19:34 by ehakam            #+#    #+#              #
#    Updated: 2021/01/11 14:58:31 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

# Source Files (.c).
SRC  =	engine/ft_camera.c \
		engine/ft_check.c \
		engine/ft_event.c \
		engine/ft_game.c \
		engine/ft_images.c \
		engine/ft_init.c \
		engine/ft_ray.c \
		engine/ft_render.c \
		engine/ft_sprite.c \
		engine/ft_update.c \
		engine/ft_save.c \
		utils/ft_atoi.c \
		utils/ft_countchar.c \
		utils/ft_error.c \
		utils/ft_gnl.c \
		utils/ft_putnbr.c \
		utils/ft_strdup.c \
		utils/ft_strlen.c \
		utils/ft_strncmp.c \
		utils/ft_strsub.c \
		utils/ft_color.c \
		utils/ft_distance.c \
		utils/ft_free.c \
		utils/ft_lowercase.c \
		utils/ft_split.c \
		utils/ft_strjoin.c \
		utils/ft_strnchar.c \
		utils/ft_utils.c \
		utils/ft_convert.c \
		parser/ft_read.c \
		parser/ft_read_color.c \
		parser/ft_read_map.c \
		parser/ft_read_resolution.c \
		parser/ft_read_texture.c \
		parser/ft_read_utils.c
# Executable Name.
NAME =	cub3D
SS   =  ss.bmp
# Compiler.
CC   =  gcc
# Compiler Flags
FLGS =	-Wall -Wextra -Werror
# Compiler Debugging Flags
DBUG =	-g3 -fsanitize=undefined
# Compiler Optimization Flag
OPT  =	-O3
GREEN=  \033[0;32m
NC   =  \033[0m

# Main Rule:
#	- Builds the Final Exutable $(name)
#	- Use NAME=<exec_name> for a custom Executable Name.
all: $(NAME)

# Compiling Rule.
$(NAME): $(SRC)
	@echo "$(GREEN)Compiling...$(NC)"
	@$(CC) -I minilibx -lmlx -framework OpenGL -framework AppKit $(FLGS) $(SRC) -o $(NAME) $(OPT)

# Cleaning Object Files.
clean:
	@echo "$(GREEN)Cleaning...$(NC)"
	@rm -rf $(OBJ)

# Cleaning All Built Files.
fclean: clean
	@echo "$(GREEN)Full Cleaning...$(NC)"
	@rm -rf $(NAME) $(SS)

# Recompiling Rule.
re: fclean all
