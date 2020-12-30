# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 19:19:34 by ehakam            #+#    #+#              #
#    Updated: 2020/12/30 19:42:36 by ehakam           ###   ########.fr        #
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
		utils/ft_strnstr.c \
		utils/ft_utils.c \
		parser/ft_read.c \
		parser/ft_read_color.c \
		parser/ft_read_map.c \
		parser/ft_read_resolution.c \
		parser/ft_read_texture.c
# Build Directory for object files.
BUILD=	build
# Object Files.
OBJ  =  ./build/$(SRC:.c=.o)
# Executable Name.
NAME =	Cub3D
# Compiler.
CC   =  gcc
# Compiler Flags
FLGS =	-Wall -Wextra -Werror
# Compiler Debugging Flags
DBUG =	-g3 -fsanitize=undefined
# Compiler Optimization Flag
OPT  =	-O3

# Main Rule:
#	- Builds the Final Exutable $(name)
#	- Use NAME=<exec_name> for a custom Executable Name.
all: $(NAME)

# Linking Rule.
$(NAME): $(OBJ)
	@#echo ">>> Linking... <<<"
	@#$(CC) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@#
	@#clang $(SRC) -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd -lm -o $(NAME) $(DBUG)
	@#gcc -I minilibx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME) $(OPT)

# Compiling Rule.
$(OBJ) : $(SRC)
	@echo ">>> Compiling... <<<"
	@$(CC) -I minilibx $< -o $(OBJ) -c $(OPT)

# Cleaning Object Files.
clean:
	@echo ">>> Cleaning... <<<"
	@rm -rf $(OBJ)

# Cleaning All Built Files.
fclean: clean
	@echo ">>> FCleaning... <<<"
	@rm -rf $(NAME)

# Recompiling Rule.
re: clean all